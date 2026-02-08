// User function Template for C++

class Solution {
  public:
  
    bool areAnagrams(Node *root1, Node *root2) 
    {
        vector<vector<int>> tree1;
        vector<vector<int>> tree2;
        
        queue<Node*> q1;
        queue<Node*> q2;
        
        q1.push(root1);
        q2.push(root2);
        
        while(!q1.empty())
        {
            vector<int> tempans1;
            int size=q1.size();
            while(size--)
            {
                Node* temp = q1.front();
                q1.pop();
                tempans1.push_back(temp->data);
                if(temp->left)
                {
                    q1.push(temp->left);
                }
                if(temp->right)
                {
                    q1.push(temp->right);
                }
            }
            sort(tempans1.begin() , tempans1.end());
            tree1.push_back(tempans1);
        }
        
        while(!q2.empty())
        {
            vector<int> tempans2;
            int size=q2.size();
            while(size--)
            {
                Node* temp = q2.front();
                q2.pop();
                tempans2.push_back(temp->data);
                if(temp->left)
                {
                    q2.push(temp->left);
                }
                if(temp->right)
                {
                    q2.push(temp->right);
                }
            }
            sort(tempans2.begin() , tempans2.end());
            tree2.push_back(tempans2);
        }
        
        if(tree1==tree2)
        {
            return true;
        }
        
        else
        {
            return false;
        }
        
    }
};