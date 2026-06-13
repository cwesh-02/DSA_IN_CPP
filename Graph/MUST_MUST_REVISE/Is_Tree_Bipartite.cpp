class Solution {
public:

int count = 0;

    void DFS(int node , vector<bool> &visited , vector<int> &color , vector<vector<int>> &adj)
    {
        visited[node]=1;
        for(int i =0;i<adj[node].size();i++)
        {
            if(!visited[adj[node][i]])
            {
                color[adj[node][i]]=1-color[node];
                DFS(adj[node][i] , visited , color , adj);
            }
            else
            {
                if(color[adj[node][i]]==color[node])
                count++;
            }
        }
    }

    bool isBipartite(vector<vector<int>>& adj) 
    {
        int V = adj.size();
        vector<bool> visited(V,0);

        vector<int> color(V,-1);

        for(int i =0;i<V;i++)
        {
            if(!visited[i])
            {
                color[i]=1-color[i];
                DFS(i , visited , color , adj);
            }
            
        }

        if(count==0) return true;

        return false;

    }
};