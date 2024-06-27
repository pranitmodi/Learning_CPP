#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void solve(vector<int> adj[], vector<bool> &visited, int i, vector<int> &ans)
    {
        visited[i] = true;
        ans.push_back(i);
        
        vector<int> v = adj[i];
        int n = adj[i].size();
        
        for(int j=0; j<n; j++)
        {
            if(!visited[v[j]])
            {
                solve(adj,visited,v[j],ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<bool> visited(V,false);
        vector<int> ans;
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                solve(adj,visited,i,ans);
            }
        }
        
        return ans;
    }
};