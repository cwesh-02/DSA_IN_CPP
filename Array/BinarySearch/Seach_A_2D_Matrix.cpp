class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) 
    {
        int i = arr.size();        
        int j = arr[0].size(); 
        int st=0;
        int start =0;
        int end = i-1;
        int mid;
        while(start<=end)
        {
            mid=(start+end)/2;
            if(arr[mid][0]==target)
            {
                return true;
            }

            else if(arr[mid][0]<target)
            {
                st=mid;
                start=mid+1;
            }

            else
            {
                end=mid-1;
            }

        }

    cout<<mid;

        for(int i=0;i<j;i++)
        {
            if(arr[st][i]==target)
            return true;
        }

        return false;

    }
};