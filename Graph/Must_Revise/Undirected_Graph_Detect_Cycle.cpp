class Solution {
  public:
  
  vector<int> adj[100001];

  bool DetectCycle(int node , int parent , vector<bool> &visited)
  {
      visited[node]=1;
      for(int i =0;i<adj[node].size();i++)
      {
        if(parent == adj[node][i])
        {
            continue;
        }
        
        if(visited[adj[node][i]])
        {
            return 1;
        }
        
        if(DetectCycle(adj[node][i] , node , visited))
        return 1;
      }
      
      return 0;
  }
  
    bool isCycle(int V, vector<vector<int>>& edges) 
    {
        
        vector<bool> visited(V,0);
        for (int i = 0; i < V; i++)
        adj[i].clear();

        for (auto& edge : edges) 
        {
          int u = edge[0];
          int v = edge[1];
          adj[u].push_back(v);
          adj[v].push_back(u); 
        }
        
        for(int i =0;i<V;i++)
        {
            if(visited[i]==0)
            {
                if(DetectCycle(i , -1 , visited))
                return 1;
            }
        }
        
        return 0;
        
    }
};