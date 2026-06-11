class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) 
    {
        vector<vector<pair<int,int>>> adj(V);
        
        for(int i =0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back( { w , v } );
            adj[v].push_back( { w , u } );
        }
        
        vector<bool> visited(V , 0);
        vector<int> parent(V,-1);
        vector<int> weight (V,INT_MAX);
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;
        
        q.push( { 0 , 0 } );
        
        int count = 0;
        
        weight[0]=0;
        
        while(!q.empty())
        {

            int node = q.top().second;
            int w = q.top().first;
            q.pop();
            
            if(visited[node]==1)
            {
                continue;
            }
        
            visited[node]=1;
            count++;
            
            if(count==V) break;
            
            for(int i = 0 ; i< adj[node].size(); i++)
            {
                if(visited[adj[node][i].second]==0 && weight[adj[node][i].second] > adj[node][i].first)
                {
                    q.push( { adj[node][i].first , adj[node][i].second } );
                    parent[adj[node][i].second] = node;
                    weight[adj[node][i].second] = adj[node][i].first;
                }
            }
            
        }
        
        int sum = 0;
        for(int i =0;i<V;i++)
        sum+=weight[i];
        
        return sum;
        
    }
};