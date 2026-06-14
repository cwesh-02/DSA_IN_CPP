// User function Template for C++

class Solution {
  public:
  
    void solve(vector<vector<int>> &edges , vector<int> &dist)
    {
        
        for(int i =0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            if( dist[u] !=1e8 && dist[u]+w < dist[v])
            dist[v]=dist[u]+w;
            
        }
        
    }
  
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) 
    {
        vector<int> dist(V,1e8);
        
        dist[src]=0;
        
        for(int i =0;i<V-1;i++)
        {
            solve(edges , dist);
        }
        
        vector<int> ans(V);
        for(int i =0;i<V;i++)
        {
            ans[i]=dist[i];
        }
        
        solve(edges , dist);

        for(int i =0;i<V;i++)
        {
            if(ans[i]!=dist[i])
            return {-1};
        }
        
        return dist;
    }
};
