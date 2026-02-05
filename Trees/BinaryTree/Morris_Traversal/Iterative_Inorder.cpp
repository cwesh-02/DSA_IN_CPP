// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> inOrder(Node* root) 
    {
        
        //THIS IS MORRIS TRAVERSAL < CHECK OTHER SUBMISSION FOR STACK METHOD
        
        vector<int> ans;
        
        while(root)
        {
            if(!root->left)
            {
                ans.push_back(root->data);
                root=root->right;
            }
            
            else
            {
                Node* curr = root->left;
                
                while(curr->right && curr->right!=root)
                {
                    curr = curr->right;
                }
                
                if(curr->right==NULL)
                {
                    curr->right = root;
                    root=root->left;
                }
                
                else
                {
                    curr->right=NULL;
                    ans.push_back(root->data);
                    root=root->right;
                }
                
            }
        }
        
        return ans;
        
    }
};