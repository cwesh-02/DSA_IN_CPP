/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* prev=NULL;
    TreeNode* first=NULL;
    TreeNode* second = NULL;
    int count = 0;

    void solve(TreeNode* root)
    {
        if(!root) return;
        solve(root->left);

        if(!prev)
        prev = root;

        else
        {
            if(root->val<prev->val)
                {
                    count++;
                    if(count==1)
                    {
                        first = prev;
                        second = root;
                    }

                    if(count==2)
                    {
                        second=root;
                    }
                    
                }
                prev=root;
        }
        

        solve(root->right);
    }

    void recoverTree(TreeNode* root) 
    {
        solve(root); 
        swap(first->val , second->val);   
    }
};