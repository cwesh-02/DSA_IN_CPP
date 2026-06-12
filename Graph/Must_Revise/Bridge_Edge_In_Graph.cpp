
class Solution {
  public:
  
  
    bool DFS(int node , int v , vector<bool>& visited , vector<vector<int>> &adj)
    {
        if(node==v) return 1;
        
        visited[node]=true;
        
        for(int nbr : adj[node])
            {
                if(!visited[nbr])
                    {
                        if(DFS(nbr,v,visited,adj))
                            return true;
                    }
            }
        
        return 0;
    }
    
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) 
    {
        
        int u = c;
        int v = d;
        
        vector<vector<int>> adj(V);
        for(int i =0;i<edges.size();i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        for(int i =0;i<adj[u].size();i++)
        {
            if(adj[u][i]==v)
            {
            adj[u][i]=u;
            break;
            }
        }
        
        for(int i =0;i<adj[v].size();i++)
        {
            if(adj[v][i]==u)
            {
            adj[v][i]=v;
            break;
            }
        }
        
        vector<bool> visited(V,0);
        
        for(int i =0;i<adj[u].size();i++)
        {
            if(DFS(u , v , visited , adj))
            return 0;
        }
        
        return 1;
        
    }
};