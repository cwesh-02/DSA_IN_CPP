#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    int solve(Node* root, int k, vector<int> &ans)
    {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return 1;

        int left = solve(root->left, k, ans);
        int right = solve(root->right, k, ans);

        int total = left + right;

        if (total == k)
            ans.push_back(root->data);

        return total;
    }

    vector<int> btWithKleaves(Node *ptr, int k)
    {
        vector<int> ans;
        solve(ptr, k, ans);

        if (ans.empty())
            ans.push_back(-1);

        return ans;
    }
};

int main()
{
    /*
        Tree:
              1
             / \
            2   3
               / \
              4   5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    Solution obj;
    vector<int> res = obj.btWithKleaves(root, 2);

    for (int x : res)
        cout << x << " ";

    return 0;
}
