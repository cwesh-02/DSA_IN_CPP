class Solution {
  public:
    int firstElementKTime(vector<int>& arr, int k) 
    {
        int ans=0;
        unordered_map<int,int> mp;
        
        for(int i =0;i<arr.size();i++)
        {
            
            mp[arr[i]]++;
            
            if(mp[arr[i]]==k)
            {
                ans=arr[i];
                return ans;
            }
            
            
        }
        
        return -1;
        
    }
};