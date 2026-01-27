/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/


class Solution {
  public:
  
  bool solve(Node* root , int miny , int maxy)
  {
        if(root==NULL)
        {
            return true;
        }
        
        int n=root->data;
        
        if(n>=maxy || n<=miny)
        {
            return false;
        }
        
        return solve(root->left , miny , n) && solve(root->right , n , maxy);
        
  }
  
    bool isBST(Node* root) 
    {
        
        bool a = solve(root , INT_MIN , INT_MAX);
        return a;
    }
};