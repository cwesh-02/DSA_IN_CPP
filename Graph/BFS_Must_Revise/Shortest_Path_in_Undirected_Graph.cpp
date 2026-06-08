class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) 
    {
        
        vector<vector<int>> adj(V);
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> distance(V,-1);
        
        distance[src]=0;
        
        queue<pair<int,int>> q;
        //node , distance
        q.push({src , 0});
        
        while(!q.empty())
        {
            int node = q.front().first;
            int step = q.front().second;
            
            for(int i =0;i<adj[node].size();i++)
            {
                if(distance[adj[node][i]]==-1)  //adj node visited
                {
                    q.push({adj[node][i] , step+1});
                    distance[adj[node][i]]=step+1;
                }
                
                else  //not visited
                {
                    continue;
                }
            }
            
            q.pop();
        }
        
        return distance;
    }
};
