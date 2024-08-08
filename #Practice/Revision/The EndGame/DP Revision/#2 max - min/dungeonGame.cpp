// 174. Dungeon Game
#include <bits/stdc++.h>
using namespace std;

// With DP is left

// Recusrion - TLE
class Solution {
public:
    bool check(int r, int c, int m, int n)
    {
        if(r<=m && c<=n)
            return true;
        return false;
    }
    void solve(int r, int c, vector<vector<int>>& dungeon, int sum, int ans, int &res)
    {
        int m = dungeon.size()-1;
        int n = dungeon[0].size()-1;
        int ele = dungeon[r][c];

        if(ele<0)
        {
            if(sum<0)
            {
                sum += ele;
                ans = max(ans,abs(sum));
            }
            else
            {
                int d = sum + ele;
                if(d<0)
                {
                    ans += abs(d);
                    sum = 0;
                }
                else
                {
                    sum = d;
                }
            }
        }
        else if(ele>0)
        {
            if(sum<=0)
            {
                ans = max(ans,abs(sum));
                sum = ele;
            }
            else
            {
                sum += ele;
            }
        }

        if(r == m && c == n)
        {
            res = min(res,ans+1);
            return;
        }

        if(check(r+1,c,m,n))
            solve(r+1,c,dungeon,sum,ans,res);

        if(check(r,c+1,m,n))
            solve(r,c+1,dungeon,sum,ans,res);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int res = INT_MAX;
        solve(0,0,dungeon,0,0,res);
        return res;
    }
};