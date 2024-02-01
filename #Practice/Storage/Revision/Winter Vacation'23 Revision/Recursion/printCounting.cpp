#include <bits/stdc++.h>
using namespace std;
void print(int n)
{
    if(n == 0)
        return;

    cout << n << " "; // for reverse printing
    print(n-1);
    // cout << n << " "; // for printing from 1
}
int main()
{
    print(10);
}