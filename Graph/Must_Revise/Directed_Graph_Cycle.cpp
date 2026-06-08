class Solution {
  public:
  
    bool DFS(int node , vector<bool> &path ,vector<bool> & visited , vector<vector<int>> &adj)
    {
        visited[node] = 1;
        path[node]=1;
        
        for(int i =0;i<adj[node].size();i++)
        {
            if(visited[adj[node][i]]==0)
            {
                if(DFS(adj[node][i] , path , visited , adj))
                return 1;
            }
            
            else
            {
                if(path[adj[node][i]]==1)
                return 1;
            }
        }
        path[node]=0;
        
        return 0;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) 
    {
   
        bool ans=0;
        
        vector<vector<int>> adj(V);
        
        vector<bool> path(V,0);
        vector<bool> visited(V,0);

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
        }
        
        for(int i =0;i<V;i++)
        {
            if(visited[i]==0)
            {
                if(DFS(i , path , visited , adj))
                return 1;
            }
        }
        
        return 0;
        
        
        
    }
};