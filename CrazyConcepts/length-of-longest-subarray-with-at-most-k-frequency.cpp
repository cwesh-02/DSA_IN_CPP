class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        if(nums.size()==1) return 1;

        int n = nums.size();
        int result = 0;
        int culprit = 0;

        unordered_map<int,int> mp;
        int i=0;
        int j =0;
        
        while(j<n)
        {
            mp[nums[j]]++;
            if(mp[nums[j]]==k+1)
            { 
                culprit++;
            }

            if(culprit>0)
            {
                mp[nums[i]]--;

                if(mp[nums[i]]==k)
                culprit--;

                i++;
            }
            
            if(culprit==0)
            result = max(result , j-i+1);

            j++;
        }
        
        return result;

    }
};