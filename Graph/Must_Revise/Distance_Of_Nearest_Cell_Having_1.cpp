class Solution {
  public:
  
  bool check(int i , int j , int n , int m)
  {
      return i-1>=-1 && i<n && j-1>=-1 && j<m;
  }
  
    vector<vector<int>> nearest(vector<vector<int>>& grid) 
    {
        
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        
        vector<vector<int>> ans(n, vector<int>(m));
        
        for(int i =0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            
            if(grid[i][j]==1)
            {
                q.push({{i,j},0});
            }
            
            ans[i][j]=0;
            
        }
        
        int distance = 0;
        
        while(!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            distance = q.front().second;
            
            if(check(i-1 , j , n ,m))
            {
                if(grid[i-1][j]==0)
                {
                    grid[i-1][j]=1;
                    q.push({{i-1 , j} , distance+1});
                    ans[i-1][j]=distance+1;
                }
            }
            
            if(check(i+1 , j , n ,m))
            {
                if(grid[i+1][j]==0)
                {
                    grid[i+1][j]=1;
                    q.push({{i+1 , j} , distance+1});
                    ans[i+1][j]=distance+1;
                }
            }
            
            if(check(i , j-1 , n ,m))
            {
                if(grid[i][j-1]==0)
                {
                    grid[i][j-1]=1;
                    q.push({{i , j-1} , distance+1});
                    ans[i][j-1]=distance+1;
                }
            }
            
            if(check(i , j+1 , n ,m))
            {
                if(grid[i][j+1]==0)
                {
                    grid[i][j+1]=1;
                    q.push({{i , j+1} , distance+1});
                    ans[i][j+1]=distance+1;
                }
            }
            
            q.pop();
        }
        
        
        return ans;
    }
};