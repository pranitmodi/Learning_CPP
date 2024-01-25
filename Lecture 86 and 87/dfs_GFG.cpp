#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    void dfs(int node, vector<int> &ans, unordered_map<int,bool> &visited, vector<int> adj[])
    {
        visited[node] = true;
        ans.push_back(node);
        
        for(int i=0; i<adj[node].size(); i++)
        {
            if(!visited[adj[node][i]])
                dfs(adj[node][i],ans,visited,adj);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        unordered_map<int,bool> visited;
        
        dfs(0,ans,visited,adj);
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}