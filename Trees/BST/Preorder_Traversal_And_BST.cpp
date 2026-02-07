// User function Template for C++

class Solution {
  public:
  
  int idx = 0;

  void solve(int arr[] , int &N , int min , int max)
  {
    
    if(idx == N) 
    {
        return ;
    }

    if(arr[idx] < min || arr[idx] > max) return;

    int root = arr[idx];
    idx++;
    
    solve(arr, N, min, root);
    solve(arr, N, root, max);

  }
  
    int canRepresentBST(int arr[], int N) 
    {
        int min = INT_MIN;
        int max = INT_MAX;
        
        solve(arr, N, INT_MIN, INT_MAX);
        return idx == N;
    }
};