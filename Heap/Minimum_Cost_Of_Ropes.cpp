class Solution {
  public:
    int minCost(vector<int>& arr) 
    {
        int ans=0;
        priority_queue<int,vector<int> , greater<int>> p;
        for(int i =0;i<arr.size();i++)
        {
            p.push(arr[i]);
        }
        
        int first;
        int second;
        
        while(p.size()!=1)
        {
            first = p.top();
            p.pop();
            second = p.top();
            p.pop();
            
            first+=second;
            ans+=first;
            
            p.push(first);
        }
        
        return ans;
        
    }
};