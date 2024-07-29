#include <bits/stdc++.h>
using namespace std;

// Recusrion + Mem
int solve(int n, vector<int> &dp)
{
    if(n == 1)
        return 0;

    if(n == 2)
        return 1;

    if(dp[n] != -1)
        return dp[n];

    return dp[n] = solve(n-1,dp) + solve(n-2,dp);
}

// Tabulation
int tab(int n)
{
    vector<int> dp(n+1,0);
    dp[1] = 1;
    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n-1];
}

// Optimization
int tabOpt(int n)
{
    int a = 0;
    int b = 1;
    for(int i=2; i<n; i++)
    {
        int curr = a + b;
        a = b;
        b = curr;
    }
    return b;
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    vector<int> dp(n+1,-1);
    // cout << "Ans: " << solve(n,dp) << endl;

    cout << "Ans: " << tabOpt(n) << endl;
}
