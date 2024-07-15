// 1218. Longest Arithmetic Subsequence of Given Difference
#include <bits/stdc++.h>
using namespace std;

// Recusrion - TLE
int solve(int i, vector<int>& arr, int d, int w)
{
    if(i==arr.size())
        return 0;

    int a = 0;
    if(arr[i] == w)
        a = 1 + solve(i+1,arr,d,arr[i]+d);
    else
        a = solve(i+1,arr,d,w);

    return a;
}
int longestSubsequence(vector<int>& arr, int difference) 
{
    int ans = 0;
    for(int i=0; i<arr.size(); i++)
    {
        int t = 1 + solve(i+1,arr,difference,arr[i] + difference);
        ans = max(ans,t);
    }
    return ans;
}

// Normal Method
int longestSubsequence(vector<int>& arr, int difference) 
{
    vector<int> dp(arr.size()+1,1);
    int ans = 0;
    for(int i=0; i<arr.size(); i++)
    {
        int w = 1;
        int target = arr[i] - difference;
        for(int j=0; j<i; j++)
        {
            int res = 1;
            if(target == arr[j])
                res += dp[j];

            w = max(w,res);
        }

        dp[i] = w;
        ans = max(ans,dp[i]);
    }
    return ans;
}

// Tabulation using unordered map - Optimal
int longestSubsequence(vector<int>& arr, int difference) 
{
    unordered_map<int,int> dp;
    int ans = 0;
    for(int i=0; i<arr.size(); i++)
    {
        int res = 1;
        int target = arr[i] - difference;

        int tempAns = 0;
        if(dp.count(target))
            tempAns = dp[target];
        
        dp[arr[i]] = 1 + tempAns;
        ans = max(ans,dp[arr[i]]);
    }
    return ans;
}