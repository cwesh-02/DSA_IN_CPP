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

int solve(TreeNode* root, unordered_map<int,int>& mp)
{
    if(!root)
    return 0;

    int leftsum = solve(root->left,mp);
    int rightsum = solve(root->right,mp);
    int ans = root->val + leftsum+rightsum;

    mp[ans]++;

    return ans;

}

    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        unordered_map<int,int> mp;
        solve(root,mp);
        vector<int>ans;
        int m = 0;
        for(auto i : mp){
            m=max(m,i.second);
        }
        for(auto i : mp){
            if(m==i.second)ans.push_back(i.first);
        }
        return ans;
    }
};