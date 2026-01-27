/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'

class Solution {
  public:
  
  void solve(Node* root , int &k , int &ans)
  {
      
      if(!root)
      {
          return;
      }
      
          solve(root->right , k , ans);
          k--;
          
          if(k==0)
          {
              ans=root->data;
              return ;
          }
      
          solve(root->left , k , ans);
      
    }
  
    int kthLargest(Node *root, int k) 
    {
        int ans=INT_MIN;
        solve(root , k , ans);
        return ans ;
    }
};