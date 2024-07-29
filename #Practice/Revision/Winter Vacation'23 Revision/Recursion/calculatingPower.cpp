#include <bits/stdc++.h>
using namespace std;
int calPower(int a, int b)
{
    if(b == 1)
        return a;
    
    if(b == 0)
        return 1;

    if(b&1)
        return(a * calPower(a,b/2) * calPower(a,b/2));
    else
        return(calPower(a,b/2) * calPower(a,b/2));
}
int main()
{
    cout << "2^3: " << calPower(2,3) << endl;
    cout << "5^5: " << calPower(5,5) << endl;
    cout << "1^56: " << calPower(1,56) << endl;
    cout << "2^6: " << calPower(2,6) << endl;
}