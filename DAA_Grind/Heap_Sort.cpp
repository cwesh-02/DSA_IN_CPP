#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> max_heap;
    int n;
    cout<<"Enter size";
    cin>>n;

    vector<int> arr(n);
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
        max_heap.push(arr[i]);
    }

    vector<int> ans;
    while(!max_heap.empty())
    {
        ans.push_back(max_heap.top());
        max_heap.pop();
    }

    reverse(ans.begin(),ans.end());
    for(int i =0;i<n;i++)
    cout<<ans[i]<<" ";

    return 0;
}