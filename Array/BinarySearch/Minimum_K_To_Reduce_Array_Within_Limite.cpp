class Solution {
public:

bool nonPos(vector<int> nums , int k)
{
    int oper=0;
    for(int i =0;i<nums.size();i++)
    {
        oper+=nums[i]/k;

        if(nums[i]%k!=0)
        {
            oper++;
        }

    }
    long long l = 1LL * k * k;
    return oper<=l;
}

    int minimumK(vector<int>& nums) 
    {
        int start=1;
        int end=1e5;
        int n=nums.size();
        int ans=INT_MAX;

        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nonPos(nums,mid))
            {
                ans=min(ans,mid);
                end=mid-1;
            }
            else
            start=mid+1;
        }

        return ans;

    }
};