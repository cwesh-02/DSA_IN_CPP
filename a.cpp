#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> arr;
    for(int i =0;i<arr.size();i++)
    {
        for(int j =0;j<i;j++)
        {
            cout<<(arr[i].begin()+j)<<" ";
        }
    }
    return 0;
}