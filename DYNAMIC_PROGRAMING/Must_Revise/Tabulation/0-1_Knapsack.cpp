class Solution {
  public:
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) 
    {
        int idx = wt.size()-1;
        int n = wt.size();
        
        vector<int> dp(W+1 , 0);
    
        for(int i = 1 ; i<=n ; i++)
        for(int j = W ; j>0 ; j--)
        {
            if(wt[i-1]>j)
            dp[j] = dp[j];  
            
            else
            dp[j] = max(dp[j] , dp[j-wt[i-1]]  + val[i-1] );
        }
        
        return dp[W];
    }
};
