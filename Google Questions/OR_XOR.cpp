#include<bits/stdc++.h>
using namespace std;
int okay(vector<int> &A, int i, vector<int> v, int k)
{
    if(i==A.size())
    {
        if(v.size() == k)
        {
            int t=0;
            int j=k-1;

            int a = 0;
            int b = 0;
            while(t<=j)
            {
                a = a|v[t++];
                b = b|v[j--];
            }
        }
        else    
            return 0;
    }

    int a = okay(A,i+1,v,k);
    v.push_back(A[i]);
    int b = okay(A,i+1,v,k);
    v.pop_back();

    return max(a,b);
}
void solve(int N, int K, vector<int> A)
{
    int k = 2*K;
    vector<int> v;
    cout << "Ans: " << okay(A,0,v,k) << endl;
}
int main()
{
    vector<int> A = {2,4,5};
    solve(3,1,A);

    // cout << (2|0) << endl;
    // cout << (5|0) << endl;
    // cout << (2^5) << endl;
}