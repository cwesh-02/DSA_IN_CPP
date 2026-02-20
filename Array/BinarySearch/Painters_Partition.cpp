#include<bits/stdc++.h>
int findLargestMinDistance(vector<int> &boards, int k)
{

    int start =1;
    int end=0;
    int ans=INT_MAX;

    for(int i =0;i<boards.size();i++)
    {
        end+=boards[i];
        start=max(boards[i],start);
    }

    int n = boards.size();
    while(start<=end)
    {
        int mid=(start+end)/2;
        int sum =0;
        int count=1;

        for(int i =0;i<n;i++)
        {
            sum+=boards[i];
            if(sum>mid)
            {
                count++;
                sum=boards[i];
            }
        }

        if(count>k)
        {
            start=mid+1;
        }

        if(count<=k)
        {
            ans=min(ans,mid);
            end=mid-1;
        }

        
    }
    

    return ans;

}