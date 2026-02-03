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

    bool solve(TreeNode* root , long long minn , long long maxx)
    {
        if(!root) return true;

        if(root->val <= minn)
        {
            return false;
        }

        if(root->val >=maxx)
        {
            return false;
        }

        return solve(root->left , minn , root->val) && solve(root->right , root->val , maxx);
    }

    bool isValidBST(TreeNode* root) 
    {
        if(!root->left && !root->right)
        return true;

        bool a = solve(root , LLONG_MIN , LLONG_MAX);

        return a;
    }
};