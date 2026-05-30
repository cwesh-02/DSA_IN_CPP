/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
  void solve(Node* root , Node* &prev , Node* &first , Node* &second)
  {
      if(!root) return;
      
      solve(root->left , prev , first , second);
      
      if(prev)
      {
          
          if(prev->data > root->data)
          {
              //first decrease
              if(!first && !second)
              {
                  first=prev;
                  second = root;
              }
              
              else
              {
                  second = root;
              }
          }
          
      }
      
      prev = root;
      
      solve(root->right , prev , first , second);

  }
  
    void correctBST(Node* root) 
    {
        Node* prev =NULL;
        Node* first =NULL;
        Node* second=NULL;
        
        solve(root , prev , first , second);
        
        int data = first->data;
        first->data = second->data;
        second->data = data;
        
    }
};