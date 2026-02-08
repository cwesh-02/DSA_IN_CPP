class Solution {
public:
    int minimumDeletions(string s) 
    {
        int ans=INT_MAX;
        int n = s.length();

        vector<int> bBefore(n, 0), aAfter(n, 0);

       for(int i = 1; i < n; i++) 
       {
            bBefore[i] = bBefore[i-1];
            if(s[i-1] == 'b') bBefore[i]++;
       }

       for(int i =n-2;i>=0;i--)
       {
        aAfter[i]=aAfter[i+1];
        if(s[i+1]=='a') aAfter[i]++;
       }

    for(int i =0;i<n;i++)
    {
        ans = min(ans , bBefore[i] + aAfter[i]);
    }
        
    return ans;

    }

};