// Uses BFS
#include <bits/stdc++.h>
using namespace std;
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) 
{
    unordered_map<int,list<int>> adj;
    vector<int> inDegree(n+1,0);
    for(int i=0; i<edges.size(); i++)
    {   
        adj[edges[i].first].push_back(edges[i].second);
        inDegree[edges[i].second]++;
    }

    int count = 0;

    queue<int> qt;
    // nodes were present from 1 to n
    for(int i=1; i<=n; i++) // since we already including all nodes with zero indegree, thus no need for a visited mapping
    {
        if(inDegree[i] == 0)
        {
            qt.push(i);
        }
    }

    while(!qt.empty())
    {
        int ele = qt.front();
        qt.pop();
        count++;

        for(auto i:adj[ele])
        {
            inDegree[i]--;
            if(inDegree[i] == 0)
                qt.push(i);
        }
    }
    
    if(count == n) // counting the number of nodes, as in topological sort, exact n nodes will return
        return 0;
    return 1;
}