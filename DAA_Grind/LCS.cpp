#include<bits/stdc++.h>
using namespace std;

int dp[47];
int solve(int n)
{
    if(n==0) return 0;
    if(n<0) return 0;
    if(n==1 || n==2) return n;

    if(dp[n]!=-1)
    return dp[n];

    dp[n] = solve(n-1)+solve(n-2);
    return dp[n];
}

int main()
{
    cout<<"Enter N";
    int n;
    cin>>n;

    for(int i=0;i<47;i++)
    dp[i]=-1;
    
    cout<<solve(n+1);
}