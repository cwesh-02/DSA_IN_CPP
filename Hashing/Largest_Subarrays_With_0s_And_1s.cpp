class Solution {
  public:
    int maxLen(vector<int> &arr) 
    {
        int n = arr.size();
        int len=0;
        unordered_map<int,int> m;
        int sum =0;
        for(int i =0;i<n;i++)
        {
            if(arr[i]==0)
            sum--;
            
            else
            sum++;
            
            //if sum ==0
            //if sum already exists
            //doesnt exist
            
            if(sum ==0)
            {
                len = i+1;
            }
            
            else if(m.count(sum))
            {
                len=max(len , i-m[sum]);
            }
            
            else
            m[sum]=i;
            
        }
        
        return len;
        
    }
};