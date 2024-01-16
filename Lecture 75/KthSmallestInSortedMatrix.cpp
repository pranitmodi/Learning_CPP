// 378
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        priority_queue<int> q;
        int i = 0;

        for(int j=0; j<matrix.size(); j++)
        {
            for(int p=0; p<matrix.size(); p++)
            {
                if(i<k)
                    q.push(matrix[j][p]);
                else
                {
                    if(matrix[j][p] < q.top())
                    {
                        cout << matrix[j][p] << endl;
                        q.pop();
                        q.push(matrix[j][p]);
                    }
                }
                i++;
            }
        }

        return q.top();
    }
};