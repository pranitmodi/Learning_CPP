// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
#include <bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) 
{
    queue<int> qt;
    long long int i=0;
    while(i<K)
    {
        if(A[i] < 0)
            qt.push(i);
    
        i++;
    }
    
    vector<long long> ans;
    if(!qt.empty())
        ans.push_back(A[qt.front()]);
    else
        ans.push_back(0);
    
    while(i<N)
    {
        if(A[i] < 0)
            qt.push(i);
            
        while(!qt.empty() && i-qt.front()>=K)
            qt.pop();
            
        if(qt.empty())
            ans.push_back(0);
        else
            ans.push_back(A[qt.front()]);
            
        i++;
    }
    
    return ans;
    
}