#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &des, vector<int> &low, vector<vector<int>> &result, unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited)
{
    visited[node] = true;
    des[node] = low[node] = timer++;

    for(auto i:adj[node])
    {
        if(i == parent)
            continue;
        if(!visited[i])
        {
            dfs(i,node,timer, des,low,result,adj,visited);
            low[node] = min(low[node],low[i]);

            if(low[i] > low[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(i);

                result.push_back(ans);
            }
        }
        else
        {
            //Back edge
            low[node] = min(low[node],des[i]);
        }
    }


}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> des(v,-1);
    vector<int> low(v,-1); 
    int parent = -1;
    unordered_map<int,bool> visited;

    vector<vector<int>> result;

    for(int i=0; i<v; i++)
    {
        if(!visited[i])
        {
            dfs(i,parent,timer, des, low, result, adj, visited);
        }
    }

    return result;
}