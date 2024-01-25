#include <bits/stdc++.h>
using namespace std;
bool solve(int node, unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited)
{
    visited[node] = true;

    for(auto i:adj[node])
    {
        if(visited[i])
            return true;
        else
        {
            bool a = solve(i,adj,visited);
            if(a) return a;
        }
    }

    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) 
{
    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }

    unordered_map<int,bool> visited;

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            if(solve(i,adj,visited))
                return 1;
        }
        else
            return 1;
    }
    return 0;
}