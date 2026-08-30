class Solution {
public:
    int minimumDeletions(vector<int>& nums) 
    {
        int small = INT_MAX;
        int maxx = INT_MIN;
        int minidx = 0;
        int maxidx = 0;

        int n = nums.size();

        if(n==1) return 1;
        for(int i =0;i<n;i++)
        {
            if(small>nums[i])
            {
                small = nums[i];
                minidx = i;
            } 
            if(maxx<nums[i])
            {
                maxx = nums[i];
                maxidx = i;
            } 
        }

        int a = INT_MAX;
        int b = INT_MAX;

        if(maxidx>minidx)
        {
            a = min(min(maxidx+1 , n-maxidx+1 + minidx) , n-minidx);
        }
        else if(maxidx<minidx)
        {
            a = min(min( minidx+1 , n-minidx+1 + maxidx) , n-maxidx);
        }

        return a;
        
    }
};