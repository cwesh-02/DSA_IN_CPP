/*
class Node {
public:
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
  
  int Find(int x , vector<int> in , int start , int end)
  {
      
      for(int i=start;i<=end;i++)
      {
          if(in[i]==x)
          {
              return i;
          }
      }
      
  }
  
  Node* Tree(vector<int> in , vector<int> pre , int start , int end , int idx)
  {
      if(start>end)
      {
          return NULL;
      }
      
      Node* root = new Node(pre[idx]);
      
      int i = Find(pre[idx]  , in , start , end);
      
      root-> left = Tree(in , pre , start , i-1 , idx+1);
      root->right = Tree(in , pre , i+1 , end  , idx + i-start +1);
      
      return root;
  }
   
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) 
    {
        Node* root;
        root = Tree(inorder , preorder , 0 , inorder.size()-1 , 0);
        return root;
    }
};