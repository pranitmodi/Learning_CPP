#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void solve(vector<int> adj[], vector<bool> &visited, int i, vector<int> &ans)
    {
        queue<int> q;
        q.push(i);
        visited[i] = true;
        
        while(!q.empty())
        {
            int a = q.front();
            ans.push_back(a);
            q.pop();
            
            vector<int> v = adj[a];
            for(int j=0; j<v.size(); j++)
            {
                if(!visited[v[j]])
                {
                    q.push(v[j]);
                    visited[v[j]] = true;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        // Code here
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