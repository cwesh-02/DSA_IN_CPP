class Solution {
public:

    int solve(string &text1, string &text2 , int i , int j , vector<vector<int>> &dp)
    {
        if(i<0 || j <0)
        return 0;

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(text1[i]==text2[j])
        {
            dp[i][j]=1 + solve(text1 , text2 , i-1 , j-1 , dp);
            return dp[i][j];
        }

        int l1 = solve(text1 , text2 , i , j-1 , dp);
        int l2 = solve(text1 , text2 , i-1 , j , dp);
        dp[i][j] = max(l1,l2);
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) 
    {
        int n = text1.length();
        int m = text2.length();
        vector<int>dp(m+1, 0));

        for(int i =1;i<=n;i++)
        for(int j =1;j<=m;j++)
        {
            if(text1[i-1]==text2[j-1])
            {
                dp[i][j]=1 + dp[i-1][j-1];
            }
            else
            dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }

        return dp[n][m];
    }
};