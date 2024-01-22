#include <bits/stdc++.h>
using namespace std;

class graph
{
    public:
        vector<vector<int>> adj;
        int n;
        int m;

        graph(int n, int m)
        {
            this->n = n;
            this->m = m;
            adj = vector<vector<int>>(n, vector<int>(n));
        }

        void addEdge(int u, int v, bool directed)
        {
            if(!directed)
            {
                adj[v][u] = 1;
            }
            adj[u][v] = 1;
        }

        void printAll()
        {
            for(int i=0; i<n; i++)
            {
                cout << i << " -> ";
                for(int j=0; j<adj[i].size(); j++)
                {
                    if(adj[i][j])
                        cout << j << ", ";
                }
                cout << endl;
            }
        }
};
int main()
{
    int n = 5;
    int m = 6;
    graph g(n,m);

    cout << "Enter edges: " << endl;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin >> u >> v;

        // cvreating undirected graph
        g.addEdge(u,v,0);
    }

    g.printAll();
}