class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) 
    {
        vector<int> ans(nums.size() , 0);
        int n = nums.size();
        vector<int> vec = nums;
        sort(vec.begin() , vec.end());

        unordered_map<int, deque<int>> grouptolist;
        
        unordered_map<int,int> numtogroup;
        numtogroup[vec[0]] = 0; //group no.
        int group = 0;

        int prev = vec[0];

        grouptolist[0].push_back(vec[0]);
        for(int i=1;i<n;i++)
        {
            if(vec[i] - vec[i-1] > limit)
            {
                group++;
            }

            numtogroup[vec[i]]= group;
            grouptolist[group].push_back(vec[i]);
        }

        int idx =0;
        for(int i =0;i<n;i++)
        {
            int num = nums[i];
            int grp = numtogroup[num];

            ans[i] = grouptolist[grp].front();
            grouptolist[grp].pop_front();
        }
return ans;
    }
};