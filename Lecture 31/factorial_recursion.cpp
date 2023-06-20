#include <bits/stdc++.h>
using namespace std;
int fact(int n)
{
    if(n == 1)
        return 1;
    
    return (n * fact(n-1));
}
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    cout << "Factorial of " << n << "! : " <<  fact(n) << endl;

    return 0;
}
