#include <bits/stdc++.h>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<bool> visited(n+1,false);
    vector<int> parent(n+1,-1);

    vector<vector<int>> adj(n+1,vector<int>());
    for(int i=0; i<edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while(!q.empty())
            {
                int i = q.front();
                q.pop();
                for(int j=0; j<adj[i].size(); j++)
                {
                    int ele = adj[i][j];
                    if(visited[ele])
                    {
                        if(parent[i] != ele)
                            return "Yes";
                    }
                    else    
                    {
                        parent[ele] = i;
                        q.push(ele);
                        visited[ele] = true;
                    }
                }
            }
        }
    }

    return "No";
}
