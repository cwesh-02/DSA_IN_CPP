class Solution {
public:

    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        int idx = coins.size()-1;
        // int ans = solve(idx, coins, amount,dp);
        vector<int> dp(amount+1 , 1e8);
        dp[0]=0;

        for(int i =0;i<n;i++)
        {
            for(int j =coins[i];j<=amount;j++)
            dp[j] = min(dp[j] , 1+dp[j-coins[i]]);
        }

        return dp[amount] >= 1e8 ? -1 : dp[amount];
    }
};