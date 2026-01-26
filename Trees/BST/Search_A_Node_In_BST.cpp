/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
  void solve(Node* root , int key , int &ans)
  {
      if(!root)
        {
            return;
        }
        
        if(root->data==key)
        {
            ans++;
        }
        
        solve(root->left, key , ans);
        solve(root->right , key , ans);
  }
  
    bool search(Node* root, int key) 
    {
        int ans=1;
        solve(root , key , ans);
        if(ans==1)
        {
            return 0;
        }
        
        else
        {
            return 1;
        }
    }
};