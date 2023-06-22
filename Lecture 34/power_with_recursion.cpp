#include <bits/stdc++.h>
using namespace std;
int power(int a, int b)
{
    if(b == 0)
        return 1;
    if(b == 1)
        return a;

    // int ans = power(a, b/2);

    if(b&1)
        return a * power(a, b/2) * power(a, b/2);
    else
        return power(a, b/2) * power(a, b/2);
}
int main()
{
    int a,b;
    cout << "Enter the base number: ";
    cin >> a;

    cout << "Enter the power: ";
    cin >> b;

    int ans = power(a,b);
    cout << "Power: " << ans << endl;
    return 0;
}