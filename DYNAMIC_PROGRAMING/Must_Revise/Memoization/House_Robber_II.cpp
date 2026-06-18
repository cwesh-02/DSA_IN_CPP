class Solution {
public:

    int solve(int st , int end , vector<int> &nums , vector<int> &dp)
    {
        if(dp[st]!=-1) return dp[st];

        if(st>end) return 0;
        int cost1 = nums[st] + solve(st+2 , end , nums , dp);
        int cost2 = solve(st+1 , end , nums , dp);

        return dp[st]=max(cost1 , cost2);
    }

    int rob(vector<int>& nums) 
    {
        vector<int> dp1(nums.size()+2 , -1);
        vector<int> dp2(nums.size()+2 , -1);
        int st = 0;
        int end = nums.size()-1;
        int firsthalf = solve(0 , end-1 , nums , dp1);
        int secondhalf = solve(1 , end , nums , dp2);

        if(nums.size()==1) return nums[0];
        return max(firsthalf , secondhalf);
    }
};