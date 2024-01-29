#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0; i<g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i=0; i<=n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    // taking 1 as the starting node
    key[1] = 0;

    // it needs to run for these many number of times, one less than the number of nodes
    for(int i=1; i<n; i++)
    {
        int mini = INT_MAX;
        int u;

        // find the node with minimum key and mst == false;
        for(int j=1; j<=n; j++)
        {
            if(mst[j] == false && key[j] < mini)
            {
                u = j;
                mini = key[j];
            }
        }

        // mark mst as true and traverse all the adjacent nodes
        mst[u] = true;
        for(auto w:adj[u])
        {
            int v = w.first;
            int wt = w.second;

            if(mst[v] == false && wt < key[v]) // now check the weights with respect to this node, if less -> update
            {
                parent[v] = u;
                key[v] = wt;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=n; i++)
    {
        ans.push_back(make_pair(make_pair(parent[i],i), key[i]));
    }
    return ans;
}