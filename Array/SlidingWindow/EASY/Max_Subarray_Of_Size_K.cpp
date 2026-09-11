class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) 
    {
       int n = arr.size();
        int ans = 0;
        int sum = 0;
        
        for(int i =0;i<k;i++)
        {
            sum+=arr[i];
        }
        ans = sum;
        int fp = 0;
        int sp = k;
        
        while(sp<n)
        {
            sum -= arr[fp];
            sum += arr[sp];
            
            ans = max(ans , sum);
            sp++;
            fp++;
        }
        
        return ans;
        
    }
};