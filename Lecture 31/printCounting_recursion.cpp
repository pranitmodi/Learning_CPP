#include <bits/stdc++.h>
using namespace std;
int printCount(int n)
{
    if(n == 0)
    {
        return 0;
    }

    // cout << n << " ";
    printCount(n-1);
    cout << n << " ";
}
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    printCount(n);

    return 0;
}
