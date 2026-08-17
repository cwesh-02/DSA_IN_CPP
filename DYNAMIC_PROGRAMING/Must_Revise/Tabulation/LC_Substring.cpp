class Solution {
  public:
    
    // int solve(string& s1, string& s2 , int i , int j , int &ans , vector<vector<int>> &dp)
    // {
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
        
    //     int len=0;
    //     if(s1[i]==s2[j])
    //     {
    //         len = 1+solve(s1 , s2 , i-1 , j-1 , ans , dp);
    //         ans = max(ans , len);
    //     }
        
    //     solve(s1 , s2 , i-1 , j , ans , dp);
    //     solve(s1 , s2 , i , j-1 , ans , dp);
        
    //     return dp[i][j] = len;
    // }
  
    int longCommSubstr(string& s1, string& s2) 
    {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));
        
        int ans = 0;
        
        for(int i = 1 ; i<=m ; i++)
        {
            for(int j = 1 ; j<=n ;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                    ans = max(ans , dp[i][j]);
                }
                
                else
                dp[i][j] = 0;
            }
        }
        
        return ans;
    }
};