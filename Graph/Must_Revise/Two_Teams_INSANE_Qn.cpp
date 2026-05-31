int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A + 1);
    for (auto &edge : B) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    vector<int> color(A + 1, -1);
    
    for(int i = 1; i <= A; i++) {
        if(color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0; // Start with color 0
            
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                
                // Use 'v' to avoid shadowing the outer 'i'
                for(int v : adj[u]) { 
                    if(color[v] == -1) {
                        // Assign the OPPOSITE color of the parent 'u'
                        color[v] = 1 - color[u]; 
                        q.push(v);
                    } 
                    else if(color[v] == color[u]) {
                        // If an enemy has the same color, bipartition is impossible
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}