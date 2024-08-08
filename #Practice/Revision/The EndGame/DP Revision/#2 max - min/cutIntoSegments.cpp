#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &arr, vector<int> &dp)
{
	if(n == 0)
        return 0;

    if(n<0)
        return -1;

    if(dp[n] != -1)
        return dp[n];

    int maxi = -1;
    for(int i=0; i<=2; i++)
    {
        if(n-arr[i] >= 0 && solve(n-arr[i],arr,dp) != -1)
            maxi = max(maxi,solve(n-arr[i],arr,dp)+1);
    }

    return dp[n] = maxi;
}
int cutSegments(int n, int x, int y, int z) {
	vector<int> arr = {x,y,z};
    vector<int> dp(n+1,-1);

    int ans = solve(n,arr,dp);
    if(ans == -1)
        return 0;
    return ans;
}