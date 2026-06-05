class Solution {
  public:
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
        vector<int> count(V,0);
        
        for(int i =0;i<V;i++)
        {
            for(int j =0 ; j< adj[i].size();j++)
            {
                count[adj[i][j]]++;
            }
        }
        
        vector<int> ans;
        
        queue<int> q;
        
        for(int i =0;i<V;i++)
        {
            if(count[i]==0)
            q.push(i);
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            for(int i =0;i<adj[node].size();i++)
            {
                count[adj[node][i]]--;
                if(count[adj[node][i]]==0)
                q.push(adj[node][i]);
            }
        }
        
        return ans;
        
    }
};