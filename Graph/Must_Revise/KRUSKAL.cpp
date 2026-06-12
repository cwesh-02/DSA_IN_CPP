class Solution {
  public:
  
    int findPar(int u , vector<int> & parent)
    {
        if(u==parent[u])
        return u;
        
        return findPar(parent[u] , parent);
    }
  
    bool disjoinSet(int u , int v , vector<int>& parent , vector<int> &rank)
    {
        int pu = findPar(u , parent);
        int pv = findPar(v , parent);
        
        if(pu==pv) return 1;
        
        if(rank[pu]==rank[pv])
        {
            rank[pu]++;
            parent[pv]=pu;
        }
        
        else if(rank[pu]>=rank[pv])
        {
            parent[pv]=pu;
            rank[pv]++;
        }

        else
        {
            parent[pu]=pv;
            rank[pu]++;
        }
        
        
        return 0;
    }
  
  
  
  
  
  
int spanningTree(int V, vector<vector<int>>& edges) 
    {
        vector<vector<pair<int,int>>> adj(V);
        
        vector<int> parent(V);
        
        for(int i =0;i<V;i++)
        {
            parent[i]=i;
        }
        
        vector<int> rank(V);
        
        for(int i =0;i<V;i++)
        {
            rank[i]=0;
        }
        
        for(int i =0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back( { w , v } );
            adj[v].push_back( { w , u } );
        }
        
        
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> q;
        
        for(int i =0;i<V;i++)
        {
            int node = i;
            
            for(int j = 0 ; j < adj[node].size();j++)
            {
                int w = adj[node][j].first;
                int u = i;
                int v = adj[node][j].second;
                
                q.push( { w , { u , v } } );
            }
        }
        
        int edge_count=0 , cost=0;
        
        while(!q.empty())
        {
            if(edge_count==V-1)
            break;
            
            int u = q.top().second.first;
            int v = q.top().second.second;
            int w = q.top().first;
            
            q.pop();
            
            if(disjoinSet(u,v, parent , rank))
            {
                continue;
            }
            
            else{
                cost+=w;
                edge_count++;                
            }
            
        }
        
        return cost;
        
        
    }
};