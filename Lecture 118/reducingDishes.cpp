// 
#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(vector<int>& satisfaction, int i, vector<int> &v)
{
    if(i==satisfaction.size())
    {
        // sort(v.begin(),v.end());
        int sum = 0;
        int t = 1;
        for(int i:v)
            sum += (t++ * i);

        return sum;
    }

    int a = solve(satisfaction,i+1,v);
    v.push_back(satisfaction[i]);
    int b = solve(satisfaction,i+1,v);
    v.pop_back();

    return max(a,b);
}
int maxSatisfaction(vector<int>& satisfaction) 
{
    vector<int> v;
    sort(satisfaction.begin(),satisfaction.end());
    return solve(satisfaction,0,v);
}