#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, n;
    cout << "Enter the Values of a and N" << endl;
    cin >> a >> n;

    int m;
    cout << "Enter modulo value: ";
    cin >> m;

    int res = 1;
    while(n>0)
    {
        if(n&1) //checking n is odd
            res = (1LL * (res)%m * (a)%m)%m;
        
        a = (1LL * (a)%m * (a)%m)%m;
        n = n>>1; //dividing n by 2
    }

    cout << "Answer: " << res << endl;
    return 0;
}