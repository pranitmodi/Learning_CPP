// There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes. 

#include <bits/stdc++.h>
using namespace std;
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