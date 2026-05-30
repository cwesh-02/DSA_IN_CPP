#include <bits/stdc++.h>
using namespace std;


void merge(vector<int> &arr , int st , int mid , int end)
{
    int i = st;
    int j = mid+1;

    vector<int> temp;

    while(i<=mid && j<=end)
    {
        if(arr[i]<=arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }

        else if(arr[i]>arr[j])
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid)
        {
            temp.push_back(arr[i]);
            i++;            
        }

        while(j<=end)
        {
            temp.push_back(arr[j]);
            j++;            
        }

    int k=0;
    for(int i =st ;i<=end;i++)
    {
        arr[i] = temp[k++];
    }

}

void MS(vector<int> &arr , int st , int end)
{
    if(st>=end) return;
    if(arr.size()==1) return;

    int mid = (st+end)/2;

    MS(arr , st , mid);
    MS(arr , mid+1 , end);
    merge(arr , st , mid , end);
}

int main()
{
    vector<int> arr(5);
    int n =5;

    for(int i =0;i<n;i++)
    {
        cout<<"Enter "<<i<<" th"<<" number";
        cin>>arr[i];
    }

    MS(arr , 0 , n-1);
    for(int i =0;i<n;i++)
    cout<<arr[i]<<" ";
    return 0;
}