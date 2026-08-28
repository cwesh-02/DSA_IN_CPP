class Solution {
public:

    bool solve(unordered_map<string,int> &mp , int idx , string &s , int &n , vector<int> &dp)
    {
        if(idx==n) return 1;
        if(dp[idx]!=-1) return dp[idx];

        for(int l = 1 ; l<=n ; l++)
        {
            string sub = s.substr( idx , l);
            if(mp.count(sub) && solve(mp , idx+l , s , n , dp)) 
            {
                return dp[idx] = 1;
            }
        }

        return dp[idx] = 0;
        
        
    }

    bool wordBreak(string s, vector<string>& wordDict) 
    {
        vector<int> dp(s.length()+1, -1);

        unordered_map<string,int> mp;
        int n = s.length();

        for(int i =0;i<wordDict.size();i++)
        {
            mp[wordDict[i]]++;
        }

        if(mp.count(s)) return true;
        int idx = 0;

        return solve(mp , idx , s , n , dp);
        

    }
};

//USING TABULATION

  bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n = s.length();

        vector<int> dp(n+1, 0);

        unordered_map<string,int> mp;
        
        for(int i =0;i<wordDict.size();i++)
        {
            mp[wordDict[i]]++;
        }
        dp[n]=1;

        if(mp.count(s)) return true;
        int idx = 0;
        
        for(int i=n;i>=0;i--)
        {
            for(int l = 1 ; i+l<=n ; l++)
            {
                string sub = s.substr( i , l);
                if(mp.count(sub) && dp[i+l]==1) 
                {
                    dp[i] = 1;
                }
            }
        }

        return dp[0];

    }
};