    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        // bool buy = 1;
        // int t = 2;
        // int idx = 0;
        
        // vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(3 , vector<int>(2 , -1)));

        int total = 0;

        vector<vector<int>> dp(3 , vector<int>(n+1 , 0));
        for(int i =1;i<3;i++)
        {
            total = -prices[0];
            for(int j = 1 ;j<=n;j++)
            {
                dp[i][j]= max(dp[i][j-1] , prices[j-1]+total);
                total = max(total , -prices[j-1] + dp[i-1][j]);
            }
        }

        return dp[2][n];