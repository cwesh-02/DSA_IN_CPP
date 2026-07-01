class Solution {
public:

    int solve(int idx , vector<int> & coins , int amount , vector<vector<int>> &dp)
    {

        if(amount==0) return 0;
        if(idx<0) return 1e8;
        if(amount<0) return 1e8;
        
        if(dp[idx][amount]!=-1)
        {
            return dp[idx][amount];
        }
        // if(coins[idx]>amount) return solve(idx-1 , coins , amount);

        return dp[idx][amount] = min(1+solve(idx , coins , amount-coins[idx] , dp) , solve(idx-1 , coins , amount , dp));
    }

    int coinChange(vector<int>& coins, int amount) 
    {
        vector<vector<int>> dp(coins.size()+1 , vector<int> (amount+1 , -1));

        int idx = coins.size()-1;
        int ans = solve(idx, coins, amount,dp);
    
        if(ans==1e8) return -1;
        return ans;
    }
};