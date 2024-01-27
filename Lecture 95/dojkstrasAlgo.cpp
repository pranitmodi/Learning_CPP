#include <bits/stdc++.h> 
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) 
{
    unordered_map<int,list<pair<int,int>>> adj;
    // undirected graph
    for(int i=0; i<vec.size(); i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int z = vec[i][2];

        adj[u].push_back(make_pair(v,z));
        adj[v].push_back(make_pair(u,z));
    }
    
    vector<int> dist(vertices,INT_MAX);
    set<pair<int,int>> s;

    dist[source] = 0;
    s.insert(make_pair(0,source));
    while(!s.empty())
    {
        pair<int,int> top = *(s.begin()); // s.begin() returns the iterator, thus * dereferences and returns the element itself
        int ele = top.second;
        s.erase(s.begin());

        for(auto i:adj[ele])
        {
            if((top.first + i.second) < dist[i.first])
            {
                dist[i.first] = top.first + i.second;
                s.insert(make_pair(dist[i.first],i.first));
            }
        }
    }

    return dist;
}