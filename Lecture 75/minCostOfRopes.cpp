#include <bits/stdc++.h>
using namespace std;
//Function to return the minimum cost of connecting the ropes.
long long minCost(long long arr[], long long n) {
    priority_queue<long long,vector<long long>,greater<long long>> q;
    long long ans = 0;
    
    for(int i=0; i<n; i++)
        q.push(arr[i]);
        
    while(n>1)
    {
        long long a = q.top();
        q.pop();
        long long b = q.top();
        q.pop();
        
        ans += (a + b);
        q.push((a+b));
        n--;
    }
    
    return ans;
}