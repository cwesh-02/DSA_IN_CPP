class Solution {
  public:
  
    int solve(string s1 , string s2 , int i , int j , vector<vector<int>> &dp)
    {
        if(i<0 || j<0)
        return 0;
            
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(i==j)
        {
            return dp[i][j] = max(solve(s1 , s2 , i-1 , j , dp) , solve(s1 , s2 , i , j-1 , dp));
        }
        
        else if(s1[i]==s2[j])
        return dp[i][j] = 1 + solve(s1 , s2 , i-1 , j-1 , dp);
        
        else
        return dp[i][j] = max(solve(s1 , s2 , i-1 , j , dp) , solve(s1 , s2 , i , j-1 , dp));
    }
    
    int longestRepSubseq(string &s1) 
    {
        string s2 = s1;
        int i =s1.length()-1;
        int j = s2.length()-1;
        
        vector<vector<int>> dp(s1.length()+1 , vector<int>(s2.length()+1 , -1));
        
        return solve(s1 , s2 , i , j , dp);
    }
};