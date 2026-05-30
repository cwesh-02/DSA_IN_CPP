class Solution {
  public:
    int maxLength(vector<int>& arr) 
    {
        unordered_map<int , int> mp;
        int len=0;
        int n = arr.size();
        int sum = 0;
        mp[0]=-1;
        for(int i =0;i<n;i++)
        {
            sum+=arr[i];
            if(mp.count(sum))
            {
                len=max(len,i-mp[sum]);
            }
            else
            {
                mp[sum]=i;
            }
        }
        
        if(sum==0)
        return n;
        
        else
        return len;
        
    }
};