class Solution {
  public:
  
  class Node
  {
      public:
      
      Node* left;
      Node* right;
      int freq;
      
      Node(int count)
      {
            freq = count;
            left = right = NULL;
      }
      
  };
  
  class compare
  {
      public:
      bool operator()(Node* a , Node* b)
      {
          return a->freq>b->freq;
      }
  };
  
  void preorder(Node* root , string s , vector<string> &huff)
  {
      if(!root) return;
      
      if(!root->left && !root->right){
      huff.push_back(s);
      return;
      }
      
      preorder(root->left , s+"0" , huff);
      preorder(root->right , s+"1" , huff);
      
  }
  
    vector<string> huffmanCodes(string S, vector<int> f, int N) 
    {

        priority_queue<Node* , vector<Node*> , compare> minheap;
        for(int i =0;i<N;i++)
        {
            Node* root = new Node(f[i]);
            minheap.push(root);
        }
        
        Node* root;
        Node* min1;
        Node* min2;
        
        while(minheap.size()>1)
        {
            min1 = minheap.top();
            minheap.pop();
            min2 = minheap.top();
            minheap.pop();
            
            Node* root = new Node(min1->freq + min2->freq);
            root->left = min1;
            root->right = min2;
            
            minheap.push(root); // Doubt
        }
        
        root= minheap.top();
        vector<string> huff;
        preorder(root , "" , huff);
        return huff;
        
    }
};