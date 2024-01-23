#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void bfs(int node, vector<int> adjList[], unordered_map<int,bool> &visited, vector<int> &ans)
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
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
            unordered_map<int,bool> visited;
            vector<int> ans;
            int i=0;
            if(!visited[i])
                bfs(i,adj,visited,ans);
            
            // for(int i=0; i<V; i++)
            // {
            //     if(!visited[i])
            //         bfs(i,adj,visited,ans);
            // }
        
            return ans;
    }
};