class Solution {
public:

    bool solve(string &s , int i , int j , vector<vector<int>> &dp)
    {
        if(i>=j) return 1;

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(s[i]==s[j])
        return dp[i][j] = solve(s , i+1 , j-1 , dp);

        return 0;
    }
    
    string longestPalindrome(string s1) 
    {
        int lp =0;
        int rp =s1.length()-1;

        int maxLength = 0;
        int start = -1;

        vector<vector<int>> dp(s1.size()+1 , vector<int>(s1.size()+1 , -1));

        for(int i=0;i<s1.length();i++)
        {
            for(int j =i;j<s1.length();j++)
            {
                if(solve(s1 , i , j , dp)==true)
                {
                    if(j-i+1>maxLength)
                    {
                        maxLength=j-i+1;
                        start=i;
                    }
                }

            }
        }

        return s1.substr(start, maxLength);

    }
};