#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int k;
    cin>>k;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int ans = 0;

    int zeroes = 0;
    int left = 0;
    int right = 0;

    while(right<n)
    {
        if(nums[right] == 0)
        {
            zeroes++;
        } 

        if(zeroes>k)
        {
            while(zeroes>k)
            {
                if(nums[left]==0) 
                zeroes--;
                
                left++;
            }
        }

        ans = max(ans , right-left+1);
        right++;
    }
    
    cout<<ans<<endl;

    return 0;
}