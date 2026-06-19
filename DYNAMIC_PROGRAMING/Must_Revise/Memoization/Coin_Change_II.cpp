class Solution {
public:

    int solve(int idx , int amount , vector<int>& coins , vector<vector<int>>& dp)
    {

        if(amount==0) return 1;
        if(idx<0) return 0;
        
        if(dp[idx][amount]!=-1) return dp[idx][amount];

        if(amount<coins[idx]) return dp[idx][amount]=solve(idx-1 , amount , coins , dp);

        return dp[idx][amount]=solve(idx , amount-coins[idx] , coins , dp) + solve(idx-1 ,amount , coins , dp);

    }

    int change(int amount, vector<int>& coins) 
    {
        int idx = coins.size()-1;
        vector<vector<int>> dp(coins.size() , vector<int>(amount+1 , -1));
        return solve(idx , amount , coins , dp);
        //Thinking While Applying DP
        //idx ka range kya hoga?  ->  [coins.size()-1 , 0]   ie.. coins.size() ki dp bnegi
        //amount ka range?  ->  [0 , amount]    ie.. amount+1 ki dp bnegi
    }
};