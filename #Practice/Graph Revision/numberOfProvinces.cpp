// 547. Number of Provinces
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<vector<int>>& isConnected, int i, vector<bool> &visited)
    {
        visited[i] = true;
        int n = isConnected.size();

        for(int j=0; j<n; j++)
        {
            if(isConnected[i][j] && !visited[j])
            {
                solve(isConnected,j,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        vector<bool> visited(n,false);

        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                ans++;
                solve(isConnected,i,visited);
            }
        }
        
        return ans;
    }
};