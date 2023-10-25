#include <bits/stdc++.h>
using namespace std;
double moreAccurate(int ans, int val)
{
    if((ans*ans) == val)
        return (double)ans;

    double s = ans + 0.01;
    double e = ans + 0.99;
    double mid = 0;

    while(s <= e)
    {
        // cout << s << " " << e << endl;
        mid = s + (e-s)/2;
        if((mid*mid) == val)
            break;
        else if((mid*mid) < val)
            s = mid + 0.01;
        else
            e = mid - 0.01;
    }
    return mid;
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int s = 1;
    int e = n;
    int mid = 0;
    while(s<=e)
    {
        mid = s + (e-s)/2;
        int sqr = mid * mid;

        // cout << s << " " << e << endl;

        if(sqr == n)
        {
            break;
        }
        else if(sqr < n)
            s = mid + 1;
        else    
            e = mid - 1;
    }

    double answ = moreAccurate(mid,n);
    cout << "Ans: " << fixed << setprecision(2) << answ << endl;

    return 0;
}