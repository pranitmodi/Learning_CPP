#include<bits/stdc++.h>
using namespace std;

// Approach 1: Recursion + memorization
int fibb(int n, vector<int> &dp)
{
    if(n==0 || n==1)
        return n;
    
    if(dp[n] != -1)
        return dp[n];

    dp[n] = fibb(n-1,dp) + fibb(n-2,dp);
    return dp[n];
}

// Approach 2: Tabulation
int fibb2(int n)
{
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// Approach 3: Space Optimization
int fibb3(int n)
{
    if(n<=1)
        return n;

    int a = 0;
    int b = 1;

    for(int i=2; i<=n; i++)
    {
        int curr = a+b;
        a = b;
        b = curr;
    }

    return b;
}

int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;

    vector<int> dp(n+1,-1);
    cout <<  fibb(n,dp) << endl;
    cout <<  fibb2(n) << endl;
    cout <<  fibb3(n) << endl;
}