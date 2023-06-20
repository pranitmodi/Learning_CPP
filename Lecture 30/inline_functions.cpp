#include <bits/stdc++.h>
using namespace std;

inline int getMax(int &a, int &b) //Inline function
{
    cout << "a: " << a << "  b: " << b << endl;
    return a>b ? a : b;
}

int main()
{
    int a = 2;
    int c = 4;

    int ans = getMax(a,c);

    cout << "Answer: " << ans;
    return 0;
}