class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long sum = 0;
        int n = nums.size();
        vector<int> ans(n,0);

        if(nums[0]==0) ans[0] = 1;

        for(int i =1;i<n;i++)
        {
            if(ans[i-1]!=0 && nums[i]==0)
            {
                ans[i] = ans[i-1] + 1;
            }

            else if(nums[i]==0) ans[i] = 1;
        }

        for(int i =0;i<n;i++)
        sum+=ans[i];

        return sum;
    }
};