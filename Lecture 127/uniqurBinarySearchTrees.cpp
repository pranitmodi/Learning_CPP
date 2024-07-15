// 96. Unique Binary Search Trees
#include <bits/stdc++.h>
using namespace std;

// Mannual Tabulation
int numTrees(int n) 
{
    vector<int> dp(n+1,0);
    dp[1] = 1;
    for(int i=2; i<=n; i++)
    {
        int res = 0;
        for(int j=1; j<=i; j++)
        {
            int left = j-1;
            int right = i-j;

            if(left!=0 && right!=0)
                res += (dp[left]*dp[right]);
            else
                res += max(dp[left],dp[right]);
        }
        dp[i] = res;
    }    
    return dp[n];
}