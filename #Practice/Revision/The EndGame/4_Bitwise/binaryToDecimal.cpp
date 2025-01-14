#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter a binary number:";
    cin >> n;

    int ans = 0;
    int count = 1;

    int n1 = n;
    while(n1!=0)
    {
        int d = n1%10;
        if (d)
            ans += count;
        count = count*2;
        n1 = n1/10;
    }

    cout << "Decimal conversion is: " << ans << endl;
}