// 983. Minimum Cost For Tickets
#include <bits/stdc++.h>
using namespace std;

// Recusrion
int solve(vector<int>& days, vector<int>& costs, int i)
{
    if(i>=days.size())
        return 0;

    vector<int> d={1,7,30};

    int mini = INT_MAX;
    for(int j=0; j<costs.size(); j++)
    {
        int w = i;
        while(w<days.size() && days[w]<(days[i]+d[j]))
            w++;

        int ans = solve(days,costs,w);
        if(ans!=INT_MAX)
            mini = min(mini,ans+costs[j]);
    }

    return mini;
}

// Recusrion + Memorization
class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int i, vector<int> &dp)
    {
        if(i>=days.size())
            return 0;

        vector<int> d={1,7,30};

        if(dp[days[i]]!=INT_MAX)
            return dp[days[i]];

        int mini = INT_MAX;
        for(int j=0; j<costs.size(); j++)
        {
            int w = i;
            while(w<days.size() && days[w]<(days[i]+d[j]))
                w++;

            int ans = solve(days,costs,w,dp);
            if(ans!=INT_MAX)
                mini = min(mini,ans+costs[j]);
        }

        return dp[days[i]] = mini;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days[days.size()-1]+1,INT_MAX);
        return solve(days,costs,0,dp);
    }
};

// Same Memorization, but different dp size
class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int i, vector<int> &dp)
    {
        if(i>=days.size())
            return 0;

        vector<int> d={1,7,30};

        if(dp[i]!=INT_MAX)
            return dp[i];

        int mini = INT_MAX;
        for(int j=0; j<costs.size(); j++)
        {
            int w = i;
            while(w<days.size() && days[w]<(days[i]+d[j]))
                w++;

            int ans = solve(days,costs,w,dp);
            if(ans!=INT_MAX)
                mini = min(mini,ans+costs[j]);
        }

        return dp[i] = mini;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,INT_MAX);
        return solve(days,costs,0,dp);
    }
};

// Tabulation
int mincostTickets(vector<int>& days, vector<int>& costs)
{
    vector<int> dp(days.size()+1,INT_MAX);
    vector<int> d={1,7,30};
    
    dp[days.size()] = 0;
    for(int k=days.size()-1; k>=0; k--)
    {
        int mini = INT_MAX;
        for(int j=0; j<costs.size(); j++)
        {
            int w = k;
            while(w<days.size() && days[w]<(days[k]+d[j]))
                w++;

            int ans = dp[w];
            if(ans!=INT_MAX)
                mini = min(mini,ans+costs[j]);
        }
        dp[k] = mini;
    }

    return dp[0];
}

// Space Optimization - O(1)
int mincostTickets(vector<int>& days, vector<int>& costs) 
{
    int ans = 0;
    queue<pair<int,int>> month;
    queue<pair<int,int>> week;

    for(int day:days)
    {
        // remove expired days
        while(!month.empty() && month.front().first + 30 <= day)   
            month.pop();

        while(!week.empty() && week.front().first + 7 <= day)   
            week.pop();

        // add cost for current days
        week.push(make_pair(day,ans+costs[1]));
        month.push(make_pair(day,ans+costs[2]));

        ans = min(ans+costs[0], min(week.front().second,month.front().second));
    }

    return ans;
}