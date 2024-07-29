// https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    void solve(queue<int> &q, int k, int i)
    {
        if(i > k)
            return;
            
        int val = q.front();
        q.pop();
        solve(q,k,i+1);
        
        q.push(val);
    }
    queue<int> modifyQueue(queue<int> q, int k) 
    {
        solve(q,k,1);
        int l = q.size();
        
        for(int i=1; i<=(l-k); i++)
        {
            int val = q.front();
            q.pop();
            q.push(val);
        }
        
        return q;
    }
};