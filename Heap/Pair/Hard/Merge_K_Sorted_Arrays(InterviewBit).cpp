vector<int> Solution::solve(vector<vector<int> > &A) 
{
    vector<int> ans;
    int row = A.size();
    int col=A[0].size();
    //pair<int,pair<int,int>>
    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> minheap;
    
    // Insert 1st column in min heap;
    
    
    for(int i =0;i<row ; i++)
    {
        if(!A[i].empty()) 
        {
            minheap.push(make_pair(A[i][0], make_pair(i, 0)));
        }
    }
    
    pair<int,pair<int,int>> temp;
    
    while(!minheap.empty())
    {
        //get min element (at top)
        temp = minheap.top();
        //Insert the value in ans
        minheap.pop();
        ans.push_back(temp.first);
        
        int row=temp.second.first;
        int col = temp.second.second;
    
        //Insert next element of that row ,
        
        if(col<A[0].size()-1 )
        minheap.push(make_pair(A[row][col+1] , make_pair(row , col+1)));
        //before check if row is exhausted or not
    }
    
    return ans;
}
