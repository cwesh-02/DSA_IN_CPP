class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        if(nums.size()==1) return 1;

        int n = nums.size();
        int result = 0;

        unordered_map<int,int> mp;
        int i =0 , j = 0;

        while(j<nums.size())
        {
            mp[nums[j]]++;

            while(i<j && mp[nums[j]]>k)
            {
                mp[nums[i]]--;
                i++;
            }

        result = max(result , j-i+1);
        j++;
            
        }

        return result;

    }
};