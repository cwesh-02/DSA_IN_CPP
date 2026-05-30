#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V=4;
    vector<vector<int>> adj[V];
    adj[0].push_back({1,3});

    adj[1].push_back({0,3});
    adj[1].push_back({3,2});
    adj[1].push_back({2,5});

    adj[2].push_back({1,5});
    adj[2].push_back({3,9});    
    
    adj[3].push_back({1,2});
    adj[3].push_back({2,9});  

    vector<bool> IsMST(V,0);
    vector<int> parent(V);
    int cost =0;
    
    priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
    pq.push({0 , {0,-1}});

    while (!pq.empty())
    {
        int node = pq.top().second.first;
        int wt = pq.top().first;
        int par = pq.top().second.second;
        
        pq.pop();
        
        if(!IsMST[node])
        {
            IsMST[node]=1;
            cost+=wt;
            parent[node]=par;
        }

        for(int i =0;i<adj[node].size();i++)
        {
            if(!IsMST[adj[node][i][0]])
            {
                pq.push({adj[node][i][1], {adj[node][i][0] , node}});
            }
        }

    }

    cout<<cost;
    
    return 0;
}
