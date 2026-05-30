#include <bits/stdc++.h>
using namespace std;

int dp[1000];
int t[1000][1000];
// teri maa ki chut
// madharchod 

int fib(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    
    int ans = fib(n-1)+fib(n-2);
    dp[n]=ans;
    return ans;
}

int main()
{
    int n;
    cout<<"Enter n";
    cin>>n;

    memset(dp,-1,sizeof(dp));
    memset(t,-1,sizeof(t));

    cout<<fib(n);
    return 0;
}