class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) 
    {
        int n = nums.size();
        // 0 1 2 3 
        //[5,0,1,4]

        vector<int> numsmax(n , nums[0]);
        vector<int> numsmin(n , nums[n-1]);

        int idx = 0;
        
        int curr_max = INT_MIN;

        for(int i = 0;i<n;i++)
        {
            numsmax[i] = max(curr_max , nums[i]);
            curr_max = numsmax[i];
        }
        
        int curr_min = INT_MAX;

        for(int i = n-1;i>=0;i--)
        {
            numsmin[i] = max(curr_min , nums[i]);
            curr_min = numsmin[i];
        }

        for(int i =0;i<n;i++)
        {
            if(numsmax[i] - numsmin[i] <= k)
            return numsmax[i] - numsmin[i];
        }

        return -1;
    }
};