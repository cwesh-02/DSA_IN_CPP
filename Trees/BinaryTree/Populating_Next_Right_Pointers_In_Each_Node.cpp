/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(!root) return NULL;
        Node* temp=NULL;
        queue<Node*> q;
        vector<vector<Node*>> v;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<Node*> tempv;

            while(size--)
            {
                temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                tempv.push_back(temp);
            }

            v.push_back(tempv);
        }

        for(int i =0;i<v.size();i++)
        {
            for(int j = 0;j<v[i].size()-1;j++)
            {
                if(v[i][j+1])
                v[i][j]->next = v[i][j+1];

                else
                v[i][j]->next = NULL;
            }
        }

        return root;

    }
};