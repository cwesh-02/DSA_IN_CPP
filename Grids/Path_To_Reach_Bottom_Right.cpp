class Solution {
  public:
    int numberOfPaths(int m, int n) 
    {
        if(n==0 || m == 0) return 1;
        if(m==1 || n ==1)
        return 1;
        
        vector<vector<int>> grid(m , vector<int>(n , 1));
        
        for(int i=m-2 ; i>=0 ; i--)
        {
            for(int j = n-2 ; j>=0 ; j--)
            {
                grid[i][j] = grid[i+1][j] + grid[i][j+1];
            }
        }
        
        return grid[0][0];
    }
};
