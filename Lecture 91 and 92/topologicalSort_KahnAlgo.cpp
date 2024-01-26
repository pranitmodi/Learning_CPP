// Uses BFS
#include <bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) 
{
    unordered_map<int,list<int>> adj;
    vector<int> inDegree(v,0);
    for(int i=0; i<edges.size(); i++)
    {   
        adj[edges[i][0]].push_back(edges[i][1]);
        inDegree[edges[i][1]]++;
    }

    vector<int> ans;

    queue<int> qt;
    for(int i=0; i<v; i++) // since we already including all nodes with zero indegree, thus no need for a visited mapping
    {
        if(inDegree[i] == 0)
            qt.push(i);
    }

    while(!qt.empty())
    {
        int ele = qt.front();
        qt.pop();
        ans.push_back(ele);

        for(auto i:adj[ele])
        {
            inDegree[i]--;
            if(inDegree[i] == 0)
                qt.push(i);
        }
    }
    return ans;
}