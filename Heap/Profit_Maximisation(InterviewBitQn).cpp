int Solution::solve(vector<int> &A, int B) 
{
    int sum =0;
    int n = A.size();
    priority_queue<int> q;
    for(int i =0;i<n;i++)
    {
        if(A[i])
        {
            q.push(A[i]);
        }
    }
    
    //Max Heap ban chuki hai
    
    while(B && q.size())
    {
        sum+=q.top();
        if(q.top()>1)
        {
            q.push(q.top()-1);
        }
        q.pop();
        B--;
    }
    
    return sum;
    
}
