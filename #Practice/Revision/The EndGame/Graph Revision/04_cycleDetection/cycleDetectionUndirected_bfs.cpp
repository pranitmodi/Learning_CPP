// Just visited array is not sufficient
// We need an array to keep track of the parents
bool solve(int i, vector<bool> &visited, vector<int> &parent, vector<vector<int>> &adj)
{
    visited[i] = true;

    for(int j=0; j<adj[i].size(); j++)
    {
        int ele = adj[i][j];
        if(visited[ele])
        {
            if(parent[i] != ele)
                return true;
        }
        else    
        {
            parent[ele] = i;
            bool a = solve(ele,visited,parent,adj); 
            if(a) return a;
        }
    }

    return false;
}
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
            if (solve(i,visited,parent,adj)) return "Yes";
    }

    return "No";
}
