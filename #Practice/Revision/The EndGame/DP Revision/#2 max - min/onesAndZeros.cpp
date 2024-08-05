// 474. Ones and Zeroes
#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int i, vector<int> &one, vector<int> &zero, int m, int n, int a, int b)
{
    if(i>=one.size() || a>m || b>n)
        return 0;

    int y = 0;
    int x = solve(i+1,one,zero,m,n,a,b);

    if(a+one[i] <= m && b+zero[i] <= n)
        y = solve(i+1,one,zero,m,n,a+one[i],b+zero[i]) + 1;

    return max(x,y);
}
int findMaxForm(vector<string>& strs, int m, int n) 
{
    vector<int> one;
    vector<int> zero;

    for(int i=0; i<strs.size(); i++)
    {
        string s = strs[i];
        int a = 0;
        int b = 0;
        for(int w=0; w<s.length(); w++)
        {
            if(s[w] == '1')
                a++;
            else
                b++;
        }

        one.push_back(a);
        zero.push_back(b);
    }    

    return solve(0,one,zero,n,m,0,0);
}

// Rec + Mem
int solve(int i, vector<int> &one, vector<int> &zero, int m, int n, int a, int b, vector<vector<vector<int>>> &dp)
{
    if(i>=one.size() || a>m || b>n)
        return 0;

    if(dp[i][a][b] != -1)
        return dp[i][a][b];

    int y = 0;
    int x = solve(i+1,one,zero,m,n,a,b,dp);

    if(a+one[i] <= m && b+zero[i] <= n)
        y = solve(i+1,one,zero,m,n,a+one[i],b+zero[i],dp) + 1;

    return dp[i][a][b] = max(x,y);
}
int findMaxForm(vector<string>& strs, int m, int n) 
{
    vector<int> one;
    vector<int> zero;

    for(int i=0; i<strs.size(); i++)
    {
        string s = strs[i];
        int a = 0;
        int b = 0;
        for(int w=0; w<s.length(); w++)
        {
            if(s[w] == '1')
                a++;
            else
                b++;
        }

        one.push_back(a);
        zero.push_back(b);
    }    

    vector<vector<vector<int>>> dp(one.size()+1, vector<vector<int>>(n+1,vector<int>(m+1,-1)));
    return solve(0,one,zero,n,m,0,0,dp);
}