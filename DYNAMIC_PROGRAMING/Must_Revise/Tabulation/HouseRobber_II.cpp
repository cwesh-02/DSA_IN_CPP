class Solution {
public:
//tabulation use kiya hai , after figuring out the top to bottom approach
    int rob(vector<int>& nums) 
    {
        if(nums.size()==1) return nums[0];
        int n = nums.size();

        vector<int> dp1(nums.size()+1 , -1);
        vector<int> dp2(nums.size()+2 , -1);

        int st = 0;
        int end = nums.size()-1;

        dp1[n-1]=dp1[n]=0;
        dp2[n+1]=dp2[n]=0;

        for(int i=n-2;i>=0;i--)
        {
            dp1[i]=max(dp1[i+2] + nums[i] , dp1[i+1]);
        }

        for(int i = n-1;i>0;i--)
        {
            dp2[i]=max(dp2[i+2] + nums[i] , dp2[i+1]);
        }
        
        return max(dp1[0] , dp2[1]);
    }
};