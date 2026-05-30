/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution {
  public:
    vector<int> findSpiral(Node* root) 
    {
        vector<int> ans;
        Node* temp;
        
        if(!root)
        {
            return ans;
        }
        
        int turn =0;
        
        queue<Node*> q;
        stack<Node*> s;
        q.push(root);
        
        while(!q.empty())
        {
            
            if(turn%2==0)
            {
                
                int size = q.size();
                while(size--)
                {
                    temp = q.front();
                    q.pop();
            
                    if(temp->right)
                    {
                        s.push(temp->right);
                    }
                
                    if(temp->left)
                    {
                        s.push(temp->left);
                    }
                        ans.push_back(temp->data);
                }
                
                turn++;
            }
            
            else
            {
                
                int size = q.size();
                while(size--)
                {
                    temp = q.front();
                    q.pop();
                
                    if(temp->left)
                    {
                        s.push(temp->left);
                    }
                
                if(temp->right)
                    {
                        s.push(temp->right);
                    }
                    
                    ans.push_back(temp->data);

                }
                
                turn++;
            }
            
            while(!s.empty())
            {
                q.push(s.top());
                s.pop();
            }
            
            
        }
        
        return ans;
    }
};