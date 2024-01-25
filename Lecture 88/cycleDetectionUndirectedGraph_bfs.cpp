#include <bits/stdc++.h>
using namespace std;
bool solve(int node, unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited)
{
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(node);
    visited[node] = true;
    parent[node] = -1;

    while(!q.empty())
    {
        int ele = q.front();
        q.pop();

        for(auto i:adj[ele])
        {
            if(visited[i] && i != parent[ele])
            {
                return true;
            }
            else if(!visited[i]) // nothing to be done when parent itself is coming in the adjList of child
            {
                q.push(i);
                visited[i] = true;
                parent[i] = ele;
            }
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

    unordered_map<int,bool> visited;
    
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            if(solve(i,adj,visited))
                return "Yes";
        }
    }
    return "No";
}