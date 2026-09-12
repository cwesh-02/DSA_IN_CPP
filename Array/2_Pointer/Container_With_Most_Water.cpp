class Solution {
public:
    int maxArea(vector<int>& nums) 
    {
        int n = nums.size();
        int fp = 0;
        int sp = n-1;

        int area = 0;
        int ans = 0;

        while(fp<sp)
        {
            area = (sp-fp) * (min(nums[fp] , nums[sp]));
            ans = max(area , ans);

            if(nums[fp] < nums[sp])
            {
                fp++;
            }

            else
            sp--;
        }

        return ans;
    }
};