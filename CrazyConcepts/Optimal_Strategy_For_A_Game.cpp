class Solution {
  public:
  
    pair<int,int> solve(bool player , int &n ,vector<int> &arr , int fp , int sp , vector<vector<vector<pair<int,int>>>> &dp)
    {
        if (fp > sp) return {0, 0};
        if(dp[fp][sp][player].first != -1) return dp[fp][sp][player];
        
        if(fp == sp)
        {
            if(player == 0)
            return dp[fp][sp][player]= {arr[fp] , 0};
            
            else
            return dp[fp][sp][player] = {0 , arr[fp]};
        }
        
        pair<int,int> left , right;
        if(player == 0)
        {
            left = solve(1 , n , arr , fp+1 , sp , dp);
            right = solve(1 , n , arr , fp , sp-1 , dp);
            
            left.first+=arr[fp];
            right.first+=arr[sp];
            
            if(left.first>right.first) return dp[fp][sp][player] = left;
            
            else return dp[fp][sp][player] = right;
        }
        
        else
        {
            left = solve(0 , n , arr , fp+1 , sp , dp);
            right = solve(0 , n , arr , fp , sp-1 , dp);
            
            left.second+=arr[fp];
            right.second+=arr[sp];
            
            if(left.second>right.second) return dp[fp][sp][player] = left;
            
            else return dp[fp][sp][player] = right;            
        }
        
    }
    
    int maximumAmount(vector<int> &arr) 
    {
        int n = arr.size();
        int fp = 0;
        int sp = n-1;
        bool player = 0;
        
// dp[n][n][2] initialized with {-1, -1}
vector<vector<vector<pair<int, int>>>> dp(
    n, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(2, {-1, -1}))
);
        pair<int,int> ans = solve(player , n , arr , fp , sp , dp);
        return ans.first;
    }
};