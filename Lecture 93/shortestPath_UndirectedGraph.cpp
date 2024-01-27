#include <bits/stdc++.h>
using namespace std;

// Approach 1 - TLE
bool solve(int node, vector<int> &ans, int t, unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited)
{
    visited[node] = true;
    ans.push_back(node);
    if(node == t)
    {
		visited[node] = false;
		return true;
	}

    vector<int> dummy = ans;
	vector<int> d = ans;
    int f = INT_MAX;
    for(auto i:adj[node])
    {
        if(!visited[i])
        {
            if(solve(i,ans,t,adj,visited))
			{
				if(ans.size() < f) // if found, checking for the shortest path out of all possible paths, with different neighbours
				{
					dummy = ans;
					f = ans.size();
				}
			}
			ans = d;
        }
    }

	ans = dummy;
    visited[node] = false;
	if(dummy.size() != d.size()) // if no changes in size
	{
		return true;
	}
	return false;
}
vector<int> shortestPath(vector<pair<int,int>> edges , int n , int m, int s , int t)
{
    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans;
    unordered_map<int,bool> visited;
    solve(s,ans,t,adj,visited);

    return ans;
}

// Approach 2
vector<int> shortestPath(vector<pair<int,int>> edges , int n , int m, int s , int t)
{
    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans;
    unordered_map<int,bool> visited;
    vector<int> parent(n+1);
    
    queue<int> qt;
    qt.push(s);
    parent[s] = -1;
    visited[s] = true;

    while(!qt.empty())
    {
        int ele = qt.front();
        qt.pop();

        for(auto i:adj[ele])
        {
            if(!visited[i])
            {
                parent[i] = ele;
                visited[i] = true;
                qt.push(i);
            }
        }
    }

    int ele = t;
    ans.push_back(ele);
    while(ele != s)
    {
        ele = parent[ele];
        ans.push_back(ele);
    }

    reverse(ans.begin(),ans.end());
    return ans;
}