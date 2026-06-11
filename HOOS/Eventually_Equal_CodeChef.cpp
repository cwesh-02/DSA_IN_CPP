#include <bits/stdc++.h>
using namespace std;

int solve(int x , int y)
{
    
    int ans = 1;
    int big = max(x , y);
    int small = min(x , y);
    
    while(small!=0)
    {
        int rem = big%small;
        
        big = small;
        small = rem;
    }
    
    return big;
    
}

int main() 
{
	
	int T;
	cin>>T;
	
	while(T--)
	{
	int A,B,C;
	cin>>A>>B>>C;
	int count = 0;
	
	if(A==B) cout<<0<<endl;
	
	else if(solve(A,C)==solve(B,C))
	{
	    cout<<1<<endl;
	}

    else if(solve(A,C+1) == solve(B,C+1))
    {
        cout<<2<<endl;
    }
    
    else
    cout<<3<<endl;
    
	}

}
