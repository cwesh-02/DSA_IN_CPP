class Solution {
  public:
  
    int solve(int idx , int W, vector<int> &val, vector<int> &wt  , vector<vector<int>> &dp)
    {
        if(idx<0)
        return 0;
        
        if(dp[idx][W]!=-1)
        return dp[idx][W];
        
        if(wt[idx]>W)
        return dp[idx][W] = solve(idx-1 , W , val , wt  , dp);
        
        else
        return dp[idx][W] = max(solve(idx-1 , W , val , wt , dp) , val[idx] + solve(idx-1 , W-wt[idx] , val , wt  , dp)) ;
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) 
    {
        int idx = wt.size()-1;
        int n = wt.size();
        
        int sum = 0;
        
        vector<vector<int>> dp(n+1 , vector<int>(W+1 , -1));
        return solve(n-1 , W , val , wt  , dp);
    }
};
