class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) 
    {
    
    vector<int> ans;
    priority_queue<int , vector<int> , greater<int>> p;
    
    int n = arr.size();
    for(int i =0;i<k;i++)
    {
        p.push(arr[i]);
    }
    
    for(int i=k ; i<n ; i++)
    {
        if(arr[i]>p.top())
        {
            p.push(arr[i]);
            p.pop();
        }
    }
    
    while(!p.empty())
    {
        ans.push_back(p.top());
        p.pop();
    }
    reverse(ans.begin() , ans.end());
    
    return ans;
    }
};