class Solution {
public:

static bool compareByValue(const pair<int, int>& a, const pair<int, int>& b) 
{
    return a.second < b.second; 
}

    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mp;

        for(int i =0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        vector<pair<int,int>> dummy(mp.begin() , mp.end());
        sort(dummy.begin() , dummy.end() , compareByValue);

        for(int i =0;i<dummy.size();i++)
        cout<<dummy[i].first<<endl<<dummy[i].second<<endl;

        vector<int> ans;
        int x = 1;
        while(k--)
        {
            ans.push_back(dummy[dummy.size()-x].first);
            x++;
        }

        return ans;
    }

};