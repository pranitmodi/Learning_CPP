#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K)
    {
        priority_queue<int,vector<int>,greater<int>> qt;   
        
        int w = 0;
        for(int i=0; i<N; i++)
        {
            int sum = 0;
            for(int j=i; j<N; j++)
            {
                sum += Arr[j];
                
                if(w<K)
                {
                    qt.push(sum);
                    w++;
                }
                else
                {
                    if(qt.top() < sum)
                    {
                        qt.pop();
                        qt.push(sum);
                    }
                }
            }
        }

        return qt.top();
    }
};