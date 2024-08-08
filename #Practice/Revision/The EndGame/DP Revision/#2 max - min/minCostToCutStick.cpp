//1547. Minimum Cost to Cut a Stick
#include <Bits/stdc++.h>
using namespace std;

int solve(int s, int e, vector<int>& cuts, int x, int y, vector<vector<int>> &dp)
{
    if(s > e)
        return 0;

    if(dp[s][e] != -1)
        return dp[s][e];

    int mini = INT_MAX;
    for(int i=s; i<=e; i++)
    {
        int a = solve(s,i-1,cuts,x,cuts[i],dp);
        int b = solve(i+1,e,cuts,cuts[i],y,dp);
        mini = min(mini, a+b);
    }

    return dp[s][e] = mini + (y-x);
}
int minCost(int n, vector<int>& cuts) 
{
    sort(cuts.begin(),cuts.end());
    int s = 0;
    int e = cuts.size()-1;    

    vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
    return solve(s,e,cuts,0,n,dp);
}