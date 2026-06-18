class Solution {
public:

    int rob(vector<int>& nums) 
    {
        if(nums.size()==1) return nums[0];
        int n = nums.size();

        // vector<int> dp1(nums.size()+1 , -1);
        // vector<int> dp2(nums.size()+2 , -1);

        // int st = 0;
        // int end = nums.size()-1;

        // dp1[n-1]=dp1[n]=0;
        // dp2[n+1]=dp2[n]=0;

        // for(int i=n-2;i>=0;i--)
        // {
        //     dp1[i]=max(dp1[i+2] + nums[i] , dp1[i+1]);
        // }

        // for(int i = n-1;i>0;i--)
        // {
        //     dp2[i]=max(dp2[i+2] + nums[i] , dp2[i+1]);
        // }
        int first = 0;
        int second = 0;
        int ans = 0;

        for(int i=n-2;i>=0;i--)
        {
            ans = max(nums[i]+second , first);
            second = first;
            first = ans;
        }

        int f =0;
        int sec = 0;
        int ans1=0;

        for(int i = n-1;i>0;i--)
        {
            ans1 = max(nums[i]+sec , f);
            sec=f;
            f = ans1;        
        }

        return max(ans , ans1);
    }
};