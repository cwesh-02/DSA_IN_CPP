int Solution::nchoc(int A, vector<int> &B) 
{
    long long ans = 0;
    long long mod = 1000000007;
    priority_queue<int> p;
    for(int i =0;i<B.size();i++)
    {
        p.push(B[i]);
    }
    
    while(A>0 && !p.empty())
    {
        ans = (ans + p.top()) % mod;
        int temp = p.top()/2;
        p.pop();
        p.push(temp);
        A--;
    }
    
    return ans;
}