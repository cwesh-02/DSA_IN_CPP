class Solution {
  public:
  
double solve(vector<int>& val, vector<int>& wt, int& capacity)
{
    double ans = 0;
    int cap = capacity;
    
    vector<double> vpuw(val.size());
    for(int i =0;i<val.size();i++)
    {
        vpuw[i]=(double)val[i]/wt[i];
    }
    
    priority_queue<pair<double,pair<int,int>>> q;
    
    for(int i =0;i<val.size();i++)
    {
        q.push({ vpuw[i] , { val[i] , wt[i] } });
    }
    
    while(cap>0 && !q.empty())
    {
        double vpuw = q.top().first;
        int capacity = q.top().second.second;
        int val = q.top().second.first;
        int wt = q.top().second.second;
        
        q.pop();
        if(wt<=cap)
        {
        ans+=val;
        cap-=wt;
        }
        else
        {
        ans += vpuw * cap;
        cap=0;
        }

    }
    
    return ans;
}
    
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) 
    {
        
        return solve(val , wt , capacity);
        
    }
};
