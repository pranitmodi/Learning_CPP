#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> & edges) 
{
    vector<vector<int>> ans(n, vector<int>());
    for(int i=0; i<n; i++)
    {
        ans[i].push_back(i);
    }
    for(int i=0; i<m; i++)
    {
        ans[edges[i][0]].push_back(edges[i][1]);
        ans[edges[i][1]].push_back(edges[i][0]);
    }
    return ans;
}