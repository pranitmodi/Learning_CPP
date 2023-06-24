#include <iostream>
using namespace std;
int power(int a, int b)
{
    int pro = 1;
    for(int i=1; i<=b; i++)
    {
        pro = pro * a;
    }
    return pro;
}
int main()
{
    cout << "Enter two number: " << endl;
    int a,b;
    cin >> a >> b;

    cout << "Power is: " << power(a,b) << endl;
    return 0;
}