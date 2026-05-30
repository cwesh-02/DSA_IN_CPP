class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        int curr=1;
        int streak = 0;
        int n =s.length();
        int ans =0;

        for(int i =1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                curr++;
            }

            else
            {
                ans+=min(curr , streak);
                streak = curr;
                curr =1;
            }
        }
         
    return ans + min(streak , curr);
        
    }
};