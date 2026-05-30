/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
  void solve_left(Node* root , vector<int> &ans)
  {
      if(!root)
      {
          return ;
      }
      
      if(!root->left && !root->right)
      {
          return;
      }
      
      ans.push_back(root->data);
      
      if(root->left)
      solve_left(root->left , ans);
      
      else
      solve_left(root->right , ans);
  }
  
  void solve_leaf(Node* root , vector<int> &ans)
  {
      if(!root)
      {
          return;
      }
      
      if(!root->left && !root->right)
      {
          ans.push_back(root->data);
      }
      
      solve_leaf(root->left , ans);
      solve_leaf(root->right , ans);

  }
  
  void solve_right(Node* root , vector<int> &ans)
    {
        if(!root)
        {
            return;
        }
        
        if(!root->left && !root->right)
        {
            return;
        }
        
        if(root->right)
        {
            solve_right(root->right , ans);
        }
        
        else
        {
             solve_right(root->left , ans);
        }
        
        ans.push_back(root->data);
        
    }
  
    vector<int> boundaryTraversal(Node *root) 
    {
        
        vector<int> ans;
        
        if(!root)
        {
            return ans;
        }
        
        ans.push_back(root->data);
        
        solve_left(root->left , ans);
        solve_leaf(root->left ,ans);
        solve_leaf(root->right ,ans);
        solve_right(root->right , ans);
        
        return ans;
    }
};