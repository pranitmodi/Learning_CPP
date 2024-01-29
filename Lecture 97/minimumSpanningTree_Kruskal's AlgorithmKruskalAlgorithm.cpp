#include <bits/stdc++.h>
using namespace std;
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int findParent(vector<int> &parent, int node)
{
    if(parent[node] == node)
    {
        return node;
    }
    // path compression
    parent[node] = findParent(parent,parent[node]);
    return parent[node];
}
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if(rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[u] = v;
        rank[v] ++;
    }
}
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    vector<int> parent(n);
    vector<int> rank(n);

    sort(edges.begin(),edges.end(),cmp);

    makeSet(parent,rank,n);

    int min_wt = 0;

    for(int i=0; i<edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);

        if(u != v)
        {
            min_wt += edges[i][2];
            unionSet(u,v,parent,rank);
        }
    }

    return min_wt;
}