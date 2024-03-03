// 62
#include <bits/stdc++.h>
using namespace std;

// Optimal Approach
// We need m+n-2 steps to reach (m-1 down,n-1 right)
// thus ans will be (m+n-2)C(m-1) or (m+n-2)C(n-1)
// 10C3 => (10*9*8)/(3*2*1)
int uniquePaths(int m, int n) 
{
    int N = n + m - 2;
    int r = m - 1; 
    double res = 1;
    
    for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;

    return (int)res;
}

// Approach 2 - Using Recursion - TLE
// class Solution {
// public:
//     bool check(int x, int y, int m, int n)
//     {
//         if(x>=0 && x<m && y>=0 && y<n)
//             return true;
//         return false;
//     }
//     void solve(int &ans, int a, int b, int m, int n)
//     {
//         if(a == m-1 && b == n-1)
//         {
//             ans++;
//             return;
//         }

//         int x = a+1;
//         int y = b;

//         if(check(x,y,m,n))
//         {
//             solve(ans,x,y,m,n);
//         }

//         x = a;
//         y = b+1;

//         if(check(x,y,m,n))
//         {
//             solve(ans,x,y,m,n);
//         }
//     }
//     int uniquePaths(int m, int n) 
//     {
//         int ans = 0;
//         solve(ans,0,0,m,n);
//         return ans;
//     }
// };