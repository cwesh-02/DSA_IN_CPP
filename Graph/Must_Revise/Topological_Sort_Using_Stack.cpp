class Solution {
  public:
  
    void DFS(int node , vector<bool> &visited , vector<vector<int>> &adj , stack<int> &s)
    {
        visited[node]=1;
        
        for(int i =0;i<adj[node].size();i++)
        {
            if(visited[adj[node][i]]==0)
            {
                DFS(adj[node][i] , visited , adj , s);
            }
        }
        
        s.push(node);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adj(V);
        for(int i =0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V,0);
        vector<int> ans;
        
        stack<int> s;
        
        for(int i =0;i<V;i++)
        {
            if(visited[i]==0)
            {
                DFS(i , visited , adj , s);
            }
        }
        
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
        
    }
};