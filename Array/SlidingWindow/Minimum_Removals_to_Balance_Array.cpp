class Solution {
public:
    int minRemoval(vector<int>& nums, int k) 
    {

        if(nums.size()==1)
        {
            return 0;
        }

        int i = 0;
        int j = 1;
        int n = nums.size();

        int countofans=INT_MAX;

        int minn;
        int mx;

        sort(nums.begin() , nums.end());

        while(j<nums.size())
        {
            minn = nums[i];
            mx = nums[j];

            while(i<j && (long long)mx > (long long)k * minn)
            {
                    i++;
                    minn=nums[i];
            }
                countofans = min(countofans , n-(j-i+1));
                j++;

        }

        if (countofans == INT_MAX)
            return n - 1;

        return countofans;
    }
};