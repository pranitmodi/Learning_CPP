#include <bits/stdc++.h>
using namespace std;
int fib(int n)
{
    if(n == 0 || n == 1)
       return n;

    return(fib(n-1) + fib(n-2)); 
}
int main()
{
    int n = 10;
    for(int i=1; i<=n; i++)
    {
        cout << i << "th Fibonacci element: " << fib(i) << endl;
    }
}