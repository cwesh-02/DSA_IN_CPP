class Solution {
  public:
    int lis(vector<int>& arr) 
    {
        int n = arr.size();
        
        vector<int> nums(n , 1);
        if(arr.size() == 0) return 0;
        nums[0]=1;
        
        for(int i =0 ; i<n;i++)
        {
            for(int j = i;j>=0;j--)
            {
                if(arr[j]<arr[i])
                {
                    nums[i] = max(nums[i], nums[j] + 1);
                }
            }
        }
        
        int ans = INT_MIN;
        
        for(int i =0;i<n;i++)
        ans = max(ans , nums[i]);
        
        
        return ans;
    }
};