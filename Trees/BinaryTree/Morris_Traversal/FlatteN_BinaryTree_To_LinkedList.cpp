// User function Template for C++

class Solution {
  public:
    void flatten(Node *root) 
    {
    Node* p =root;
    if(!root)
    {
        return;
    }
        while(root)
        {
            
            if(root->left)
            {
                Node* curr = root->left;
                while(curr->right)
                {
                    curr=curr->right;
                }
                
                curr->right = root->right;
                root->right=root->left;
                root->left=NULL;
                
            }
            
            else
            {
                root=root->right;
            }
            
            
        }
        

    }
};