/*The structure of Node

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

class Solution {
  public:
  
  void solve(Node* root , Node* x , vector<int> &ans , bool &flag)
  {
      if(!root)
      return;

      
      solve(root->left , x , ans , flag);
      
      if(flag==1)
      {
          ans.push_back(root->data);
          return;
      }
      
      if(root == x)
      {
          flag=1;
      }
      
      solve(root->right , x , ans , flag);
    
  }
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) 
    {
        bool flag =0;
        vector<int> ans;
        solve(root , x , ans , flag);  
        
        if(ans.size()==0)
        ans.push_back(-1);
        
        return ans[0];
    }
};