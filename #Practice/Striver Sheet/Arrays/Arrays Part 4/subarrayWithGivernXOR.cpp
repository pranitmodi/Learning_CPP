// interviewBit
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &A, int B) 
{
    map<int,int> m;
    int ans = 0;
    int sum = 0;
    m[0]++;

    for(int i=0; i<A.size(); i++)
    {
        sum = sum^A[i];
        int x = sum^B;

        ans += m[x];
        m[sum]++;   
    }

    return ans;
}