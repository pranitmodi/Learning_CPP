#include <bits/stdc++.h> 
using namespace std;
#define mod 1000000007
    
class Solution{
    public:
    long long solve(int n, int k, vector<int> &dp)
    {
         if(n == 1)
            return k;
            
        if(n == 2)
            return k + (k*(k-1)) %mod;
            
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = ((k-1) * 1LL * ((solve(n-1,k,dp)%mod) + (solve(n-2,k,dp)%mod))%mod)%mod;
    }
    long long countWays(int n, int k){
       vector<int> dp(n+1,-1);
       return solve(n,k,dp)%mod;
    }
};