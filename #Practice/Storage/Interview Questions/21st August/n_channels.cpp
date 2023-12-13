#include <bits/stdc++.h>
using namespace std;
// Question Link - https://www.thejoboverflow.com/p/p451/

// Not tested
int main(int n, int k)
{
    int n,k;
    cin >> n;
    cin >> k;
    vector<int> v(n,1);
    while(n != 1)
    {
        int c = 0;
        int i = 1;
        while(i<k)
        {
            if(c == n)
            {
                c = 0;
            }
            if(v[c] == 1)
            {
                i++;
            }
            c++;
        }
        while(v[i] != 1)
        {
            i++;
            if(i == n)
                i = 0;
        }
        v[i] = 0;
        n--;
    }
    for(int i=0; i<n; i++)
    {
        if(v[i] == 1)
            return i+1;
    }
    return -1;
}