#include <bits/stdc++.h>
using namespace std;
void print(int *p)
{
    cout << "Inside *p: " << *p << endl;
    cout << "diff *p: " << p[0] << endl;
    cout << "diff *p: " << p[1] << endl;
    cout << "diff *p: " << *(p - 1) << endl;
}
int main()
{
    int a = 2;
    int *p = &a;

    print(p);
    p = p + 1;
    p[1] = 3; //this is equal to *(p+1) = 3
    cout << "okay " << endl;
    cout << "edee" << p[1] << endl;
    print(p);
}