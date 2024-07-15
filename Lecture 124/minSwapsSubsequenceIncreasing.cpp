// 801. Minimum Swaps To Make Sequences Increasing
#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int i, vector<int> &nums1, vector<int> &nums2, bool swapped)
{
    if(i==nums1.size())
        return 0;

    int a = INT_MAX;
    int b = INT_MAX;
    int prev1 = nums1[i-1];
    int prev2 = nums2[i-1];

    if(swapped)
        swap(prev1,prev2);

    // no swap
    if(nums1[i]>prev1 && nums2[i]>prev2)
        a = solve(i+1,nums1,nums2,0);

    // swap
    if(nums1[i]>prev2 && nums2[i]>prev1) // beacuse current elemwnts will be swapped
        b = 1 + solve(i+1,nums1,nums2,1);

    return min(a,b);
}
int minSwap(vector<int>& nums1, vector<int>& nums2) 
{
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    return solve(1,nums1,nums2,0);
}

// Recursion + Memorization
int solve(int i, vector<int> &nums1, vector<int> &nums2, bool swapped, vector<vector<int>> &dp)
{
    if(i==nums1.size())
        return 0;

    int a = INT_MAX;
    int b = INT_MAX;
    int prev1 = nums1[i-1];
    int prev2 = nums2[i-1];

    if(dp[i][swapped]!=-1)
        return dp[i][swapped];

    if(swapped)
        swap(prev1,prev2);

    // no swap
    if(nums1[i]>prev1 && nums2[i]>prev2)
        a = solve(i+1,nums1,nums2,0,dp);

    // swap
    if(nums1[i]>prev2 && nums2[i]>prev1) // beacuse current elemwnts will be swapped
        b = 1 + solve(i+1,nums1,nums2,1,dp);

    return dp[i][swapped] = min(a,b);
}
int minSwap(vector<int>& nums1, vector<int>& nums2) 
{
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    vector<vector<int>> dp(nums1.size(),vector<int>(2,-1));

    return solve(1,nums1,nums2,0,dp);
}

// Tabulation
int minSwap(vector<int>& nums1, vector<int>& nums2) 
{
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    vector<vector<int>> dp(nums1.size()+1,vector<int>(2,0));

    for(int i=nums1.size()-1; i>=1; i--)
    {
        for(int j=1; j>=0; j--)
        {
            int a = INT_MAX;
            int b = INT_MAX;
            int prev1 = nums1[i-1];
            int prev2 = nums2[i-1];

            if(j) swap(prev1,prev2);

            // no swap
            if(nums1[i]>prev1 && nums2[i]>prev2)
                a = dp[i+1][0];

            // swap
            if(nums1[i]>prev2 && nums2[i]>prev1) // beacuse current elemwnts will be swapped
                b = 1 + dp[i+1][1];

            dp[i][j] = min(a,b);
        }
    }
    return dp[1][0];
}

// Space Optimization - O(1)
int minSwap(vector<int>& nums1, vector<int>& nums2) 
{
    nums1.insert(nums1.begin(),-1);
    nums2.insert(nums2.begin(),-1);
    int p = 0;
    int q = 0;
    int r = 0;
    int s = 0;

    for(int i=nums1.size()-1; i>=1; i--)
    {
        for(int j=1; j>=0; j--)
        {
            int a = INT_MAX;
            int b = INT_MAX;
            int prev1 = nums1[i-1];
            int prev2 = nums2[i-1];

            if(j) swap(prev1,prev2);

            // no swap
            if(nums1[i]>prev1 && nums2[i]>prev2)
                a = p;

            // swap
            if(nums1[i]>prev2 && nums2[i]>prev1) // beacuse current elemwnts will be swapped
                b = 1 + q;

            if(j==0)
                r = min(a,b);
            else
                s = min(a,b);
        }
        p = r;
        q = s;
    }
    return p;
}