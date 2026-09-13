class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) 
    {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin() , arr.end());
        // unordered_map<vector<int> , int> mp;

        for(int i =0;i<n;i++)   
        {
            if(i>0 && arr[i]==arr[i-1])
            continue;

            int fp = i+1;
            int sp = n-1;
            int target = -arr[i];
            
            while(fp<sp)
            {
                int sum = arr[fp] + arr[sp];
                if(sum == target)
                {                    
                    ans.push_back({arr[i] , arr[fp] , arr[sp]});
                    while(fp<sp && arr[fp] == arr[fp+1]) fp++;
                    while(fp<sp && arr[sp]==arr[sp-1]) sp--;

                    fp++;
                    sp--;
                }

                else if(sum > target)
                sp--;

                else
                fp++;
            }
        }

        return ans;
    }
};