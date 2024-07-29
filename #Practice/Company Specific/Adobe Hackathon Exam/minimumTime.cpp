#include <bits/stdc++.h>
using namespace std;

// Recusrion
class Solution {
public:
    int solve(int i, vector<int>& time, vector<int>& search, int k, vector<int>& dp) {
        if (i >= time.size())
            return 0;
        
        if (dp[i] != -1)
            return dp[i];
        
        // Option 1: Solve the current puzzle
        int ans = time[i] + solve(i+1, time, search, k, dp);
        
        // Option 2: Search in the book
        for (int j = 0; j < min(k, (int)time.size() - i); j++) {
            ans = min(ans, search[i] + solve(i+j+1, time, search, k, dp));
        }
        
        return dp[i] = ans;
    }

    int minTime(int n, vector<int>& time, vector<int>& search, int k) {
        vector<int> dp(n, -1);
        return solve(0, time, search, k, dp);
    }
};

// Tabulation
class Solution {
public:
    int minTime(int n, vector<int>& time, vector<int>& search, int k) {
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;  // Base case: no time needed after all puzzles are solved
        
        for (int i = n - 1; i >= 0; i--) {
            // Option 1: Solve the current puzzle
            dp[i] = time[i] + dp[i + 1];
            
            // Option 2: Search in the book
            for (int j = 1; j <= k && i + j <= n; j++) {
                dp[i] = min(dp[i], search[i] + dp[i + j]);
            }
        }
        
        return dp[0];
    }
};