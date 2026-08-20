class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) 
    {
        int n = arr.size();
        
        if(n<=2) return n;
        
        unordered_map<int,int> mp[n];
        int ans = 2;
        int diff = 0;
        for(int i =1;i<n;i++)
        {
            for(int j = i-1 ; j>=0 ; j--)
            {
                diff = arr[i]-arr[j];
                if(mp[j].count(diff))
                {
                    mp[i][diff] = ++mp[j][diff];
                    ans = max(ans , mp[i][diff]);
                }
                
                else
                {
                    mp[i][diff]=2;
                    ans = max(ans , 2);                
                }
            }
        }
        
        return ans;
       
    }
};