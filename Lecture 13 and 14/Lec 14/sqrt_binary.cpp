#include <bits/stdc++.h>
using namespace std;

long long int floorSqrt(int n)
{
    int s = 1;
    int e = n-1;
    long long int mid;
    long long  ans;
    while(s <= e)
    {
        mid = s + (e-s)/2;
        long long  sq = mid * mid;
        if(sq == n)
            return mid;
        else if(sq < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ans;
}

double morePrecision(int n, int count, int w)
{
    double ans = w;
    double d = 1;
    for(int i=1; i<=count; i++)
    {
        d = d/10;
        for(double j=ans+d; j*j < n; j=j+d)
        {
            ans = j;
        }
        // cout << "At, " << i << "th iteration: " << ans << endl;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;

    long long int sqr = floorSqrt(n);
    cout << "Answer: " << sqr << endl;

    int w = (int)sqr;
    double precise = morePrecision(n, 3, w);
    cout << "Precise Answer: " << precise << endl;

    return 0;
}