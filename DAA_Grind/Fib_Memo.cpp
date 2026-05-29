#include <bits/stdc++.h>
using namespace std;

vector<int> dp(1000,-1);

int fib(int n)
{
    if(n==0) return 0;
    if(n==1 || n==2) return 1;

    if(dp[n]!=-1) 
    {
        return dp[n];
    }
    int ans = fib(n-1)+fib(n-2); 
    dp[n] = ans;
    return ans;
}

int main()
{
    int n;
    cout<<"Enter n";
    cin>>n;

    cout<<fib(n);

    return 0;
}