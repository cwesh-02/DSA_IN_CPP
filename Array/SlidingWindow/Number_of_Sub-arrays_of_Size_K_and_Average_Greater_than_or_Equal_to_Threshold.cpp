class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) 
    {
        int count = 0;
        int n = nums.size();
        int sum = 0 ;

        for(int i =0;i<k;i++)
        sum+=nums[i];    

        if(sum/k >= threshold) count++;

        int fp = 0;
        int sp = k;

        while(sp<n)
        {
            sum-=nums[fp];
            fp++;

            sum+=nums[sp];
            sp++;

            if(sum/k>=threshold) count++;
        }

        return count;
    }
};