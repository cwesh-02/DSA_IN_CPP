class Solution {
  public:
  
  void solve(int node , vector<int> &visited1 , vector<vector<int>> &adj1)
  {
      visited1[node]=1;
      for(int i =0;i<adj1[node].size();i++)
      {
          if(!visited1[adj1[node][i]])
          {
              solve(adj1[node][i] , visited1 , adj1);
          }
      }
  }
  
    void DFS(int node , stack<int> &s , vector<vector<int>> &adj , vector<bool> &visited)
    {
        visited[node]=1;
        for(int i =0;i<adj[node].size();i++)
        {
            if(visited[adj[node][i]]==0)
            DFS(adj[node][i] , s , adj , visited);
        }
        
        s.push(node);
    }
  
    int kosaraju(int V, vector<vector<int>> &edges) 
    {
        // code here
        //Topological traversal krna hai and stack me store
        //Sari edges ko reverse krna hai
        //stack ko check krte jao while doing DFS traversal
        vector<vector<int>> adj(V);
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V,0);
        
        stack<int> s;
        
        for(int i =0;i<V;i++)
        {
            if(!visited[i])
            DFS(i, s , adj , visited);
        }
        
        //i have the stack now
        //now reverse the nodes
        vector<vector<int>> adj1(V);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj1[v].push_back(u);
        }
        vector<int> visited1(V,0);
        //done
        
        //now traversing through the stack
        int count = 0;
        while(!s.empty())
        {
            int node = s.top();
            if(!visited1[node])
            {
                count++;
                solve(node , visited1 , adj1);
            }
            
            else
            s.pop();
        }
        
        return count;
        
    }
};