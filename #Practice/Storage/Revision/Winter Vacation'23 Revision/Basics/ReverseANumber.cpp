#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n; 

    int w = 0;
    while(n != 0)
    {
        int d = n%10;
        w = (w*10) + d;
        n = n/10;
    }

    cout << "Reverse: " << w << endl;
}