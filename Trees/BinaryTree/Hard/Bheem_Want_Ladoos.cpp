/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution {

  public:
  
  int ans=0;
  
  void downsum(Node* root , int k)
  {
    if(!root) return;
    if(k<0) return;
    ans+=root->data;
    downsum(root->left , k-1);
    downsum(root->right , k-1);
  }
  
  int solve(Node* root , int &src , int k)
  {
      if(!root) return -1;
        if(k<0) return -1;
        
        if(root->data==src)
        {
            downsum(root , k);
            return k-1;
        }
        
        int left = solve(root->left , src , k);
        int right = solve(root->right , src , k);
        
        if(left == -1 && right==-1)
        {
            return -1;
        }
        
        else
        {
            if(left==-1) //src found at right side
            {
                ans+=root->data;
                downsum(root->left, right-1);
                return right-1;
            }
            
            else // src at left side
            {
                ans+=root->data;
                downsum(root->right, left-1);
                return left-1;
            }
        }
        
        return ans;
        
  }
  
    int ladoos(Node* root, int src, int k) 
    {
        
        solve(root , src , k);
        return ans;
    }
};
