#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) 
{
    vector<vector<int>> adj(V,vector<int>());
    for(int i=0; i<edges.size(); i++)
    {
        pair<int,int> p = edges[i];
        int a = p.first;
        int b = p.second;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    return adj;
}