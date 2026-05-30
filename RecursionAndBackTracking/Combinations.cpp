class Solution {
public:
    void solve(int start , vector<vector<int>> &ans , vector<int> &temp,int k , int n)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=start;i<=n;i++)
        {
            temp.push_back(i);
            solve(i+1 , ans , temp , k , n);
            temp.pop_back();
        }

        return;

    }

    vector<vector<int>> combine(int n, int k) 
    {
      
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1 , ans , temp , k , n);

        return ans;
    }

};