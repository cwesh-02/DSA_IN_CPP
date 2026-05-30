/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  
  int search(Node* root)
  {
      if(!root)
      {
          return -1;
      }
      
      if(root->left)
      {
          search(root->left);
      }
      
      else
      return root->data;
      
  }
  
    int minValue(Node* root) {
        // code here
        int ans = search(root);
        return ans;
    }
};