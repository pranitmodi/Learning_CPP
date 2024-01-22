#include <bits/stdc++.h>
using namespace std;
class graph
{
    public:
        unordered_map<int, list<int>> adj;

        void addEdge(int u, int v, bool direction)
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

}