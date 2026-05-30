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

vector<vector<int>> ans;

void solve(TreeNode* root , int s , vector<int>& temp)
{
    if(!root) return;

    temp.push_back(root->val);

    solve(root->left , s-root->val , temp);
    solve(root->right , s-root->val , temp);

    if(!root->left && !root->right && (s-root->val)==0) ans.push_back(temp);

    temp.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int s) 
    {
        vector<int> temp;
        solve(root , s , temp);
        return ans;
    }
};