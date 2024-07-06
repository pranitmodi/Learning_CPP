#include <bits/stdc++.h> 
using namespace std;

// Recusrion only
int solve(vector<int> &nums, int n)
{
    if(n<0)
        return 0;

    if(n == 0)
        return nums[0];

    int incl = solve(nums,n-2) + nums[n];
    int excl = solve(nums,n-1);

    return max(incl,excl);
}

// Recursion + Memorization
int solve1(vector<int> &nums, int n, vector<int> &dp)
{
    if(n<0)
        return 0;

    if(n == 0)
        return nums[0];

    if(dp[n]!=-1)
        return dp[n];

    int incl = solve1(nums,n-2,dp) + nums[n];
    int excl = solve1(nums,n-1,dp);

    return dp[n] = max(incl,excl);
}

// Tabulation
int solve2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n,0);
    dp[0] = nums[0];

    for(int i=1; i<n; i++)
    {
        int incl = nums[i] + dp[i-2];
        int excl = dp[i-1];

        dp[i] = max(incl,excl);
    }

    return dp[n-1];
}

// Space Optimization
int solve3(vector<int> &nums)
{
    int n = nums.size();
    int a = 0;
    int b = nums[0];

    for(int i=1; i<n; i++)
    {
        int incl = nums[i] + a;
        int excl = b;

        int curr = max(incl,excl);
        a = b;
        b = curr;
    }

    return b;
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    return solve1(nums,n-1,dp);
}
int main()
{
    vector<int> nums = {10,2,3,30};
    cout << solve3(nums);
}