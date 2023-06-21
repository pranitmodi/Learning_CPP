#include <bits/stdc++.h>
using namespace std;
int climb(int n)
{
    if(n < 0)
        return 0;
    
    if(n == 0)
        return 1;
        
    return (climb(n-1) + climb(n-2));       
}
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    cout << "Number of ways to reach nth stairs: " << climb(n) << endl;

    return 0;
}