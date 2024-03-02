#include <bits/stdc++.h>
using namespace std;

// not optimal
vector<int> solve(vector<int> &A, vector<int> &B, int C) 
{
    priority_queue<int,vector<int>,greater<int>> m;
    
    for(int i=0; i<A.size(); i++)
    {
        for(int j=0; j<B.size(); j++)
        {
            if(m.size()<C)
                m.push(A[i] + B[j]);
            else if(m.top() < A[i] + B[j])
            {
                m.pop();
                m.push(A[i] + B[j]);
            }
        }
    }

    vector<int> ans(C);
    while(C>0)
    {
        ans[C-1] = m.top();
        m.pop();
        C--;
    }

    return ans;
}
