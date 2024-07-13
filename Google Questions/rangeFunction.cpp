#include<bits/stdc++.h>
using namespace std;
vector<long long> solve(int N, int Q, vector<int> A, vector<vector<int>> query)
{
    vector<long long> ans;
    for(int r=1; r<=Q; r++)
    {
        vector<int> v = query[r-1];
        int a = v[0];
        int b = v[1];
        int c = v[2];
        if(a == 1)
        {
            A[b-1] = c;
        }
        else
        {
            long long sum = 0;
            for(int i=b; i<=c; i++)
            {
                long long w = 0;
                for(int j=i; j<=c; j++)
                {
                    w += (long long) A[j-1];
                    sum += w;
                }
            }

            cout << sum << " ";
            ans.push_back(sum);
        }
    }

    return ans;
}
int main()
{
    vector<int> A = {2,1,3,4,6,1};
    vector<vector<int>> query = {{2,1,2},{1,4,1},{2,4,4}};
    vector<long long> ans = solve(6,3,A,query);
}