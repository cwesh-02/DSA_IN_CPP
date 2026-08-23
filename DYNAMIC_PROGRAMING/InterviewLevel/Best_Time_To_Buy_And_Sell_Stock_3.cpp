class Solution {
public:

    int solve(int &n , vector<int>& prices , int buy , int idx , int t , vector<vector<vector<int>>> &dp)
    {

        if(t==0) return 0;
        if(idx>=n) return 0;

        if(dp[idx][t][buy]!=-1)
        return dp[idx][t][buy];

        if(buy)
        {
            return dp[idx][t][buy] = max( solve(n , prices , 1 , idx+1 , t , dp) , - prices[idx] + solve(n , prices , 0 , idx+1 , t , dp) );
        }

        else
        {
            return dp[idx][t][buy] = max( solve(n , prices , 0 , idx+1 , t , dp) , prices[idx] + solve(n , prices , 1 , idx+1 , t-1 , dp));
        }
    }

    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        bool buy = 1;
        int t = 2;
        int idx = 0;
        
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(3 , vector<int>(2 , -1)));

        return solve(n , prices , buy , idx , t , dp);
    }
};