class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string ans = "";
        if(strs.size()==0) return ans;

        sort(strs.begin() , strs.end());
        string first = strs[0];
        string last = strs.back();

        for(int i =0;i<first.size() ; i++)
        {
            if(first[i]==last[i]) ans+=first[i];

            else
            {
                return ans;
            }
        }
        
        

        return ans;
    }
};