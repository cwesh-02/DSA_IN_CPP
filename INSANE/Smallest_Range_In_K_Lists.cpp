class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& mat) 
    {
               priority_queue<pair<int, pair<int, int>>, 
               vector<pair<int, pair<int, int>>>, 
               greater<pair<int, pair<int, int>>>> minheap;        
               
        int minimum , maximum=INT_MIN;
        
        for(int i =0;i<mat.size();i++)
        {
            minheap.push(make_pair(mat[i][0] , make_pair(i,0)));
            maximum = max(maximum,mat[i][0]);
        }
        //initial Max nikal liya
        minimum = minheap.top().first;
        //Initial min nikal liya , overall range agyi
        vector<int> ans(2);
        
        ans[0]= minimum;
        ans[1]=maximum;
        // range likhli vector mei
        
        pair<int , pair<int , int>> temp;
        //kyu bnaya??
        int row , column , element;
        
        while(minheap.size() == mat.size()) //kyu ??
        {
            temp = minheap.top();
            minheap.pop();
            
            element = temp.first;
            row = temp.second.first;
            column = temp.second.second;
            
            int min = temp.first;
            int range = maximum - min;
            int prevrange = ans[1]-ans[0];
            
            if(prevrange>range)
            {
                ans.clear();
                ans.push_back(min);
                ans.push_back(maximum);
            }
            
            if(column+1<mat[row].size())
            {
                pair<int , pair<int , int>> temp;
                temp.first = mat[row][column+1];
                temp.second.first=row;
                temp.second.second=column+1;
                
                minheap.push(temp);
                
                if(mat[row][column+1]>maximum)
                maximum = mat[row][column+1];
            }
            
            
        }
        return ans;
    }
};