#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int n, vector<int> &v)
{
	if(n<0)
		return -1;

    if(n == 0)
        return 0;
	
	int maxi = -1;
	for(int i=0; i<v.size(); i++)
	{
		if(n-v[i] >= 0)
		{
			int ans = solve(n-v[i],v);
            if(ans!=-1)
			    maxi = max(maxi,ans+1);
		}
	}

	return maxi;
}

// Recursion + Memorization
int solve(int n, vector<int> &v, vector<int> &dp)
{
	if(n<0)
		return -1;

    if(n == 0)
        return 0;

    if(dp[n] != -1)
        return dp[n];
	
	for(int i=0; i<v.size(); i++)
	{
		if(n-v[i] >= 0)
		{
			int ans = solve(n-v[i],v,dp);
            if(ans!=-1)
			    dp[n] = max(dp[n],ans+1);
		}
	}

	return dp[n];
}

// Tabulation
int solve2(int n, vector<int> &v)
{
    vector<int> dp(n+1,-1);
    dp[0] = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i-v[j] >= 0 && dp[i-v[j]]!=-1)
            {
                dp[i] = max(dp[i],dp[i-v[j]]+1);
            }
        }
    }

    return dp[n];
}

int cutSegments(int n, int x, int y, int z) 
{
    vector<int> dp(n+1,-1);
	vector<int> v={x,y,z};
	int res = solve(n,v);
	if(res == -1)
		return 0;
	return res;
}
int main()
{
    vector<int> v={5,2,2};
    cout << "Ans: " << solve2(7,v);
}