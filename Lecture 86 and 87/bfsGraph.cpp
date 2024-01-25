#include <bits/stdc++.h>
using namespace std;
void bfs(int node, unordered_map<int,set<int>> &adjList, unordered_map<int,bool> &visited, vector<int> &ans)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty())
    {
        int n = q.front();
        q.pop();

        ans.push_back(n);

        for(auto i:adjList[n])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
} 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>> adjList;

    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    unordered_map<int,bool> visited;
    vector<int> ans;

    // to check for all the nodes, even if they are as a seperate component
    for(int i=0; i<vertex; i++)
    {
        if(!visited[i])
            bfs(i,adjList,visited,ans);
    }

    return ans;
}