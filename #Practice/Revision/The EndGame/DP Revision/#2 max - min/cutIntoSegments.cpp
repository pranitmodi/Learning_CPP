#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &arr)
{
	if(n<=0)
        return 0;

    int maxi = INT_MIN;
    for(int i=0; i<=2; i++)
    {
        maxi = max(maxi,solve(n-arr[i],arr)+1);
    }

    return maxi;
}
int cutSegments(int n, int x, int y, int z) {
	vector<int> arr = {x,y,z};
    return solve(n,arr);
}