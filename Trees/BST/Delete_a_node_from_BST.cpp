/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
  Node* findMin(Node* root)
  {
      Node* curr = root;
      while(curr && curr->left)
      {
          curr=curr->left;
      }
      
      return curr;
  }
  
    Node* delNode(Node* root, int x) 
    {

    if(!root) return NULL;
    
    //i found the node ( x== root->val)
    if(root->data == x)
    {
        // 0 child
        if(!root->right && !root->left)
        {
            delete root;
            return NULL;
        }
        
        //1 child -> left child  , right child

        else if(!root->right && root->left)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        else if(root->right && !root->left)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        // 2 child
        else
        {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delNode(root->right , temp->data);
        }
        
    }
    
    // x < root->val
    
    else if(root->data>x)
    {
        root->left = delNode(root->left , x);
    }
    //x > root->val
    
    else
    {
        root->right = delNode(root->right , x);
    }
    
    return root;
        
    }
};