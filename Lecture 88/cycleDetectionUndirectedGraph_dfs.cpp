#include <bits/stdc++.h>
using namespace std;
bool solve(int node, unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited, unordered_map<int,int> &parent)
{
    visited[node] = true;

    for(auto i:adj[node])
    {
        if(visited[i] && parent[node] != i)
            return true;
        else if(!visited[i])
        {
            parent[i] = node;
            bool a = solve(i,adj,visited,parent);
            if(a) // cant return directly, else loop wont happen
                return a;
        }
    }   
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adj;
    for(int i=0; i<m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,int> parent;
    unordered_map<int,bool> visited;
    
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            parent[i] = -1;
            if(solve(i,adj,visited,parent))
                return "Yes";
        }
    }
    return "No";
}