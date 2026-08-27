class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;

        for(int i=0;i<n;i++)
        {
            string natural=strs[i];

            sort(strs[i].begin() , strs[i].end());

            mp[strs[i]].push_back(natural);
        }
        
        for(const auto &[x,y] : mp)
        {
            if(y.size()!=0) ans.push_back(y);
            
        }

        return ans;


    }
};