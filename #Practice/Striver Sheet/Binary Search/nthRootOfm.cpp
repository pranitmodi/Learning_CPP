#include <bits/stdc++.h>
using namespace std;
int find(int mid, int n, int m)
{
    long long int ans = 1;
    for(int i=1; i<=n; i++)
    {
        ans = ans * mid;
        if(ans>m)
            return 2;
    }

    if(ans == m)
        return 1;
    return 0;
}
int NthRoot(int n, int m) 
{
    int start = 1;
    int end = m;

    while(start<=end)
    {
        int mid = start + (end-start)/2;
        
        int h = find(mid,n,m);
        if(h == 1)
            return mid;
        else if(h == 0)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}