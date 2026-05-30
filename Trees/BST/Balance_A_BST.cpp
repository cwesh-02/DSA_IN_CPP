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

    void inorder(TreeNode* root , vector<int> & in)
    {
        if(!root) return;

        inorder(root->left , in);
        in.push_back(root->val);
        inorder(root->right , in);
    }

    TreeNode* solve(int start , int end , vector<int> & in)
    {
        if(start>end)
        {
            return NULL;
        }

        int mid = (start+end) /2;
        TreeNode* temp = new TreeNode(in[mid]);
        temp->left = solve(start , mid-1 , in);
        temp->right = solve(mid+1 , end , in);

        return temp;
    }

    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<int> in;
        inorder(root , in);
        vector<int> arr;
        return solve(0 , in.size()-1 , in);

    }
};