/*
Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to find the least absolute difference between any node
    // value of the BST and the given integer.
    
    int solve(Node* root , int K , int &diff)
    {
        if(!root)
        {
            return INT_MAX;
        }
        
        if(root->data - K==0)
        {
            return 0;
        }
        
        else if(K>root->data)
        {
            diff = K - root->data;
            return min(diff , solve(root->right , K , diff));
        }
        
        else
        {
            diff = root->data - K;
            return min(diff , solve(root->left , K , diff));
        }
        
    }
    
    int minDiff(Node *root, int K) 
    {
        int diff = INT_MAX;
        
        
        return solve(root , K , diff);
    }
};