//n square solution
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

// nlogn solution

class Solution {
  public:
    int lis(vector<int>& arr) 
    {
        if(arr.size() == 0) return 0;
        int n = arr.size();
        
        vector<int> nums;
        nums.push_back(arr[0]);
        
        for(int i =1;i<n;i++)
        {
            int start = 0;
            int end = nums.size()-1;
            int tempidx = nums.size();
            
            while(start<=end)
            {
                int mid = (start+end)/2;
                
                if(nums[mid]>=arr[i])
                {
                    tempidx = mid;
                    end = mid-1;                    
                }
                
                else
                {
                    start = mid+1;
                }
            }
            
            if(tempidx == nums.size()) {
                nums.push_back(arr[i]);
            }
            else {
                nums[tempidx] = arr[i]; 
            }
        }
        
        return nums.size();

    }
};