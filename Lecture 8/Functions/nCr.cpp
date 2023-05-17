#include <iostream>
using namespace std;
int fac(int i)
{
    if(i == 0)
    {
        return 1;
    }
    int f=1;
    while(i>1)
    {
        f=f*i;
        i--;
    }
    return f;
}
int main()
{
    cout << "Enter N and R values: " << endl;
    int n,r;
    cin >> n >> r;
    
    int res = (fac(n))/((fac(r))*(fac(n-r)));
    cout << "nCr = " << res << endl;
    return 0;
}