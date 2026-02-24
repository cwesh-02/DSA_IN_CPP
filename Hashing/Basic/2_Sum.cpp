class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int , int> m;
        m[nums[0]]=0;
        for(int i =1;i<n;i++)
        {
            int left = target - nums[i];

            if(m.count(left)) 
            {
                // If found, we are done! Return the indices immediately.
                return {m[left], i};
            }

            if(!m.count(nums[i]))
            {
                m[nums[i]]=i;
            }

        }

        return ans;

    }
};