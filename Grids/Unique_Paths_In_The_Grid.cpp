class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m , vector<int>(n , 0));
        
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return 0;
        
        for(int i =0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(grid[i][j]==1)
                dp[i][j]=0;
                
                else
                dp[i][j]=1;
                
            }
        }
        
        for (int i = m - 1; i >= 0; i--) {
            if (dp[i][n-1] == 0) 
            {
                for (int k = i; k >= 0; k--) 
                {
                    dp[k][n-1] = 0;
                }
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--) 
        {
            if (dp[m-1][i] == 0) {
                for (int k = i; k >= 0; k--) 
                {
                    dp[m-1][k] = 0;
                }
                break;
            }
        }
   
        //0 mtlb blocked
        //1 mtlb open
                
        for(int i=m-2 ; i>=0 ; i--)
        {
            for(int j = n-2 ; j>=0 ; j--)
            {
               if(dp[i][j] == 1) 
               {
                   dp[i][j] = dp[i+1][j] + dp[i][j+1];
               }
            }
        }
        
        return dp[0][0];
    }
};