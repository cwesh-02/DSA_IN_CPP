class Solution {
public:

    int ans = INT_MIN;

    int solve(vector<int>& nums , int st , int end , int sum , vector<int> &idx)
    {

        if(idx[st]!=-1) return idx[st];

        if(st > end) 
        {
            return 0;
        }

        return idx[st] = max( nums[st] + solve(nums , st+2 , end ,sum ,idx) , solve(nums , st+1 , end , sum , idx));

    }

    int rob(vector<int>& nums) 
    {
        int st = 0;
        int end = nums.size()-1;
        int sum = 0;

        vector<int> idx(nums.size()+2,-1);
        // [1 , 2 , 3 , 1]
        // st           end

        return solve(nums , st , end , sum , idx);

    }
};