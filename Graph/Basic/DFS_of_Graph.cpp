class Solution {
  public:
    vector<int>ans;
    void df(vector<vector<int>>&adj,vector<bool>&visited,int n)
    {
        if(visited[n]==0) return;
        
        visited[n]=true;
        ans.push_back(n);
        
        for(int i=0;i<adj[n].size();i++)
        {
            int temp=adj[n][i];
            df(adj,visited,temp);
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<bool>visited(adj.size(),0);
        df(adj,visited,0);
        return ans;
    }
};