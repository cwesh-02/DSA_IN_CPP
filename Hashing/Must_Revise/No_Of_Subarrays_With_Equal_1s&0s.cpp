class Solution {
  public:
    int countSubarray(vector<int>& arr) 
    {
       
       unordered_map<int,int> m;
       int ans=0;
       int n = arr.size();
       
       vector<int> nums;
       int sum =0;
       m[0]=1;
       for(int i =0;i<n;i++)
       {
           if(arr[i]==0)
           sum--;
           
           else
           sum++;
           
           nums.push_back(sum);
       }
       
       for(int i =0;i<n;i++)
       {
           if(m.count(nums[i]))
           {
               if(nums[i]==0)
               {
                   ans+=m[nums[i]];
                   m[nums[i]]++;
               }
               
               else
               {
                   ans+=m[nums[i]];
                   m[nums[i]]++;
               }
           }
           
           else
           m[nums[i]]++;
       }
       
       return ans;
       
        
    }
};