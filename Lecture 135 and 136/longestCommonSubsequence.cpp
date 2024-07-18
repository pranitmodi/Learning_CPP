// 1143. Longest Common Subsequence
#include <bits/stdc++.h>
using namespace std;

// My Recursion
void solve(int i, string s, string sub, map<string,string> &m)
{
    if(i == s.length())
    {
        if(m.find(sub)!=m.end())
        {
            if(m[sub]!=s)
                m[sub] = "";
        }
        else
            m[sub] = s;
        return;
    }

    solve(i+1,s,sub,m);
    sub += s[i];
    solve(i+1,s,sub,m);
}
int longestCommonSubsequence(string text1, string text2) 
{
    if(text1 == text2)
        return text1.length();

    map<string,string> m;
    solve(0,text1,"",m);
    solve(0,text2,"",m);


    int maxi = 0;
    for(auto i:m)
    {
        if(i.second == "")
        {
            int l = i.first.length();
            maxi = max(maxi,l);
        }
    }
    return maxi;
}

// Recusrion 
int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if(i == s1.length() || j == s2.length())
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if(s1[i] == s2[j])
        ans = (1 + solve(i+1,j+1,s1,s2,dp));
    else
    {
        int a = solve(i+1,j,s1,s2,dp);
        int b = solve(i,j+1,s1,s2,dp);
        ans = max(a,b);
    }

    return dp[i][j] = ans;
}
int longestCommonSubsequence(string text1, string text2) 
{
    if(text1 == text2)
        return text1.length();

    vector<vector<int>> dp(text1.length(),vector<int>(text2.length(),-1));
    return solve(0,0,text1,text2,dp);
}

// Recusrion + Memorization
int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if(i == s1.length() || j == s2.length())
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if(s1[i] == s2[j])
        ans = (1 + solve(i+1,j+1,s1,s2,dp));
    else
    {
        int a = solve(i+1,j,s1,s2,dp);
        int b = solve(i,j+1,s1,s2,dp);
        ans = max(a,b);
    }

    return dp[i][j] = ans;
}
int longestCommonSubsequence(string text1, string text2) 
{
    if(text1 == text2)
        return text1.length();

    vector<vector<int>> dp(text1.length(),vector<int>(text2.length(),-1));
    return solve(0,0,text1,text2,dp);
}

// Tabulation
int longestCommonSubsequence(string text1, string text2) 
{
    if(text1 == text2)
        return text1.length();

    vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));

    for(int i=text1.length()-1; i>=0; i--)
    {
        for(int j=text2.length()-1; j>=0; j--)
        {
            int ans = 0;
            if(text1[i] == text2[j])
                ans = (1 + dp[i+1][j+1]);
            else
            {
                int a = dp[i+1][j];
                int b = dp[i][j+1];
                ans = max(a,b);
            }

            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

// Space Optimization
int longestCommonSubsequence(string text1, string text2) 
{
    if(text1 == text2)
        return text1.length();

    if(text1.length()<text2.length())
        return longestCommonSubsequence(text2,text1);

    vector<int> curr(text2.length()+1,0);
    vector<int> next(text2.length()+1,0);

    for(int i=text1.length()-1; i>=0; i--)
    {
        for(int j=text2.length()-1; j>=0; j--)
        {
            int ans = 0;
            if(text1[i] == text2[j])
                ans = (1 + next[j+1]);
            else
            {
                int a = next[j];
                int b = curr[j+1];
                ans = max(a,b);
            }

            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}