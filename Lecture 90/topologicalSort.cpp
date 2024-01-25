#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
void solve(stack<int> &st, int node, unordered_map<int,list<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    for(auto i:adj[node])
    {
        if(!visited[i])
            solve(st,i,adj,visited);
    }

    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  
{
    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    stack<int> st;
    vector<bool> visited(v); // for better time complexity

    for(int i=0; i<v; i++)
    {
        if(!visited[i])
            solve(st,i,adj,visited);
    }

    vector<int> ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}