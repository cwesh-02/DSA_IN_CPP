class Solution {
  public:
    int thirdLargest(vector<int> &arr) 
    {
        int n = arr.size();
        if (n < 3) return -1;

        int first = INT_MIN, second = INT_MIN, third = INT_MIN;

        for (int x : arr)
        {
            if (x >= first)
            {
                third = second;
                second = first;
                first = x;
            }
            else if (x >= second)
            {
                third = second;
                second = x;
            }
            else if (x >= third)
            {
                third = x;
            }
        }
        return third;
    }
};
