class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) 
    {

        unordered_map<int,int> mp;
        int n = nums.size();

        int fp = 0;
        int sp = 0;
        int count = 0;

        unordered_set unique_elements(nums.begin(), nums.end());
        int c = unique_elements.size();

        while(sp<n)
        {
            mp[nums[sp]]++;

            while(mp.size() == c)
            {
                count+=n-sp;

                mp[nums[fp]]--;
                if(mp[nums[fp]]==0)
                {
                    mp.erase(nums[fp]);
                }
                
                fp++;
            }

            sp++;
        }

        return count;

    }
};