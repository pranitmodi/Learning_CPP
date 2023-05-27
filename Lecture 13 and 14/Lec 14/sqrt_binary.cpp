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
int main()
{
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;

    long long int sqr = floorSqrt(n);
    cout << "Answer: " << sqr;
    return 0;
}