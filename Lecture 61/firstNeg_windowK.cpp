#include <bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) 
{
    queue<long long int> q;
    for(long long int i=0; i<K; i++)
    {
        if(A[i] < 0)
            q.push(i);
    }
    vector<long long> w;

    for(long long int i=K; i<N; i++)
    {
        if(q.empty())
            w.push_back(0);
        else
        {
            w.push_back(A[q.front()]);
            if(q.front() == (i-K))
                q.pop();
        }

        if(A[i] < 0)
            q.push(i);

    }

    if(q.empty())
        w.push_back(0);
    else
    {
        w.push_back(A[q.front()]);
    }

    return w;
}