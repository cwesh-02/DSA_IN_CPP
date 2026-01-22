class Solution {
  public:
    vector<vector<int>> binTreeSortedLevels(int arr[], int n)
    {
        vector<vector<int>> ans;

        if (n == 0)
            return ans;

        int p = 0;
        int two = 1;

        while (p < n)
        {
            vector<int> temp;

            for (int i = 0; i < two && p < n; i++)
            {
                temp.push_back(arr[p]);
                p++;
            }

            sort(temp.begin(), temp.end());
            ans.push_back(temp);

            two *= 2;
        }

        return ans;
    }
};
