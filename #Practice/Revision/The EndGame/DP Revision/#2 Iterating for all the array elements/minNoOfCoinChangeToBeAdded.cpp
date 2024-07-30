// 2952. Minimum Number of Coins to be Added
#include <bits/stdc++.h>
using namespace std;

// First Approach - TLE
class Solution {
public:
    void solve(int i, vector<int>& coins, int sum, vector<bool> &check, int &ans)
    {
        if(i>=coins.size())
        {
            if(sum<=check.size())
            {
                if(check[sum] == false)
                {
                    check[sum] = true;
                    ans++;
                }
            }
            return;
        }

        solve(i+1,coins,sum+coins[i],check,ans);
        solve(i+1,coins,sum,check,ans);
    }
    int minimumAddedCoins(vector<int>& coins, int target) 
    {
        int ans = 0;
        int count = 0;
        vector<bool> check(target+1,false);
        while(ans != target)
        {
            sort(coins.begin(),coins.end());

            for(int k=0; k<coins.size(); k++)
                solve(k,coins,coins[k],check,ans);

            if(ans!=target)
            {
                int i=1; 
                while(check[i] != false)
                    i++;

                coins.push_back(i);
                count++;
            }
        }

        return count;
    }
};

// Working Second Approach - Recusrion - TLE, but initial test cases passed.
void solve(int i, vector<bool> &check, vector<int>& coins, int sum, int target)
{
    if(i>=coins.size())
    {
        if(sum <= target)
            check[sum] = true;
        return;
    }

    solve(i+1,check,coins,sum,target);
    solve(i+1,check,coins,sum+coins[i],target);
}
int minimumAddedCoins(vector<int>& coins, int target) 
{
    vector<bool> check(target+1,false);
    for(int i:coins)
        check[i] = true;

    int ans = 0;

    vector<vector<int>> dp(coins.size(),)
    sort(coins.begin(),coins.end());
    solve(0,check,coins,0,target);

    for(int i=1; i<=target; i++)
    {
        if(!check[i])
        {
            ans++;
            coins.push_back(i);
            sort(coins.begin(),coins.end());
            solve(0,check,coins,0,target);
        }
    }

    return ans;
}

// Optimal solution
int minimumAddedCoins(vector<int>& coins, int target) 
{
    int ans = 0;
    int curr = 1;
    int max_target = 0;

    sort(coins.begin(),coins.end());
    
    int j = 0;
    int i = 1;
    while(i<=target && j<coins.size())
    {
        if(coins[j] > i)
        {
            ans++;
            max_target += i;
            i = max_target + 1;
        }
        else
        {
            max_target += coins[j];
            i = max_target + 1;
            j++;
        }
    }

    while(max_target < target)
    {
        ans++;
        max_target += i;
        i = max_target + 1;
    }

    return ans;
}