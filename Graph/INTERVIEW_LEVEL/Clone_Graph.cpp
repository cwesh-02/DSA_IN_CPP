/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    unordered_map<Node* , Node*> mp;
              //old node  new node

    void DFS(Node* node , Node* clonenode)
    {
        for(Node* n:node->neighbors)
        {
            if(mp[n]==NULL)
            {
                Node* clone = new Node(n->val);
                mp[n]=clone;
                clonenode->neighbors.push_back(clone);
                DFS(n , clone);
            }

            else
            clonenode->neighbors.push_back(mp[n]);
        }
    }

    Node* cloneGraph(Node* node) 
    { 
        if(node==nullptr) return nullptr;

        Node* clonenode = new Node(node->val);
        mp[node]=clonenode;
        DFS(node , clonenode);

        return clonenode;
    }
};