class Solution {
public:
    int trap(vector<int>& heights) 
    {
        int n = heights.size();
        int sum = 0;

        vector<int> left_max(n , 0);
        vector<int> right_max(n , 0);
        left_max[0] = heights[0];

        for(int i =1;i<n;i++)
        {
            left_max[i] = max(heights[i] , left_max[i-1]);
        }
        
        right_max[n-1] = heights[n-1];

        for(int i = n-2;i>=0;i--)
        {
            right_max[i] = max(right_max[i+1] , heights[i]);
        }

        for(int i =0;i<n;i++)
        {
            cout<<left_max[i]<<" ";
        }
        cout<<endl;

        for(int i =0;i<n;i++)
        {
            cout<<right_max[i]<<" ";
        }

        for(int i =0;i<n;i++)
        {
            if(sum + min(left_max[i] , right_max[i]) - heights[i] > 0)
            sum = sum + min(left_max[i] , right_max[i]) - heights[i];
        }

        return sum;
    }
};