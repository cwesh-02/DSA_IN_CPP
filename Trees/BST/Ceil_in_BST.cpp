class Solution {
  public:
  
  int ans=-1;
  
  void solve(Node* root , int x)
  {
      
    if(!root)
    {
        return;
    }
    
    if(root->data == x)
    {
        ans = x;
        return;
    }
    
    else if(x > root->data)
    {
        
        solve(root->right , x);
    }
    
    else
    {
        ans=root->data;
        solve(root->left , x);
    }
    
    
  }
  
    int findCeil(Node* root, int x) 
    {

        solve(root , x);
        return ans;
    }
};
