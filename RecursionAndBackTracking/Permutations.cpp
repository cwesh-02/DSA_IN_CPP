class Solution {
public:

    void solve(vector<int> &nums , int &n , vector<vector<int>> &ans , vector<bool> visited , vector<int> &temp)
    {
        if(temp.size()==n) 
        {
            ans.push_back(temp);
            return;
        }

        for(int i =0;i<n;i++)
        {
            if(visited[i]==0)
            {
                temp.push_back(nums[i]);
                visited[i]=1;
                solve(nums , n , ans , visited , temp);
                temp.pop_back();
                visited[i]=0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(n,0);

        solve(nums , n , ans , visited , temp);

        return ans;
    }
};