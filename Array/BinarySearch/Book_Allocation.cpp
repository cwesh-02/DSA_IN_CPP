class Solution {
  public:
    int findPages(vector<int> &books, int k) 
    {
        if(k>books.size()) return -1;
        int ans =INT_MAX;
        long long start=0;
        long long end = 0;
        int n = books.size();
        
        for(int i = 0;i<n ;i++)
        {
            if(books[i]>start)
            start = books[i];
            
            end+=books[i];
        }
        
        long long mid=0;
        
        while(start<=end)
        {
            int student =1;
            mid=(start+end)/2;
            int sum =0;
            for(int i =0;i<n;i++)
            {
                sum+=books[i];
                if(sum>mid)
                {
                    student++;
                    sum = books[i];
                }
            }
            
            if(student>k)
            start=mid+1;
            
            else
            {
                ans=mid;
                end=mid-1;
            }
            
        }

        return ans;
        
    }
};