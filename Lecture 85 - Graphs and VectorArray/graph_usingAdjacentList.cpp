#include <bits/stdc++.h>
using namespace std;

// works for all data types
template <typename T>
class graph
{
    public:
        unordered_map<T, list<T>> adj;

        void addEdge(T u, T v, bool direction)
        {
            // direction = 0 -> undirected graph
            // direction = 1 -> directed graph

            // create an edge from u to v
            adj[u].push_back(v);

            // if undirected graph, then reverse is also possible
            if(!direction)
                adj[v].push_back(u);
        }

        void printAdjList()
        {
            for(auto i:adj)
            {
                cout << i.first << " -> ";
                for(auto j:i.second)
                {
                    cout << j << ", ";
                }
                cout << endl;
            }
        }
};
int main()
{
    int n,m;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    graph<int> g; // defining int over here

    cout << "Enter edges: " << endl;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin >> u >> v;

        // cvreating undirected graph
        g.addEdge(u,v,0);
    }

    g.printAdjList();
}