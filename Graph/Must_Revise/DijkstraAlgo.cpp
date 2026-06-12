class Solution {
  public:
struct Compare
{
    bool operator()(pair<int,int>& a, pair<int,int>& b)  //iske bina pair ulta bana k bhi hoskkta tha par genmasti thi
    {
        return a.second > b.second;
    }
};
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) 
    {
        
        vector<int> dist(V,-1);
        
        vector<vector<pair<int,int>>> adj(V);

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w}); // remove if graph is directed
        }
                        //node   distance
        priority_queue<pair<int,int> , vector<pair<int,int>> , Compare> q;
        
        q.push({src , 0});
        
        while(!q.empty())
        {
            int w = q.top().second;
            int node = q.top().first;
            q.pop();
            
            if(dist[node]!=-1)
            continue;
            
            dist[node] = w;
            
            for(int i =0;i<adj[node].size();i++ )
            {
                if(dist[adj[node][i].first]==-1)
                {
                    q.push( { adj[node][i].first , w+adj[node][i].second } );
                }
            }
            
        }
        
        return dist;
        
    }
};