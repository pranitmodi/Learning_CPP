#include <bits/stdc++.h>
using namespace std;
void topologicalSort(stack<int> &s, int node, unordered_map<int,list<pair<int,int>>> &adj, unordered_map<int,bool> &visited)
{
    visited[node] = true;
    for(auto i:adj[node])
    {
        if(!visited[i.first])
        {
            topologicalSort(s,i.first,adj,visited);
        }
    }

    s.push(node);
}
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        pair<int,int> p = make_pair(edges[i][1],edges[i][2]);
        adj[edges[i][0]].push_back(p);
    }

    vector<int> ans(n,INT_MAX);
    stack<int> s; // finding topological sort
    unordered_map<int,bool> visited;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
            topologicalSort(s,i,adj,visited);
    }

    // the source node
    // src_node to src_node - distance = 0
    int src = 0;
    ans[src] = 0;

    while(!s.empty())
    {
        int ele = s.top();
        s.pop();

        if(ans[ele] != INT_MAX) // if it is still INT_MAX, then it is not the source node and cant be reached my either of the nodes earlier, since topological sort
        {
            for(auto i:adj[ele])
            {
                if((ans[ele] + i.second) < ans[i.first])
                {
                    ans[i.first] = ans[ele] + i.second;
                }
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        if(ans[i] == INT_MAX)
            ans[i] = -1;
    }

    return ans;
}