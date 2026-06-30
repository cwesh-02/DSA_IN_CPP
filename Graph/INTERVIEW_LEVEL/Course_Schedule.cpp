class Solution {
public:

    int count  =0;

    void BFS(vector<bool>& visited , vector<vector<int>>& adj , int parent , vector<int>& indegree , queue<pair<int,int>>& q)
    {

        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;

            for(int i =0;i<adj[node].size();i++)
            {
                indegree[adj[node][i]]--;

                if(indegree[adj[node][i]]==0)
                q.push({adj[node][i] , node});
            }

            q.pop();
            count++;
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& edges) 
    {
        queue<pair<int,int>> q;

        int n = numCourses;
        vector<int> indegree(n , 0);
        vector<bool> visited(n,0);
        vector<vector<int>> adj(n);

        for(int i =0;i<edges.size();i++)
        {
            int v = edges[i][0];
            int u = edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        for(int i =0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push({i , -1});
            }
        }

        BFS(visited , adj , -1 , indegree , q);

        if(count==n) return true;

        return false;
        
    }
};