#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "How many elements of Fibonnaci Series you want? " << endl;
    cin >> n;

    int a = 0;
    int b = 1;
    int c;
    int i = 1;
    while (i <= n)
    {
        if(i == n)
        {
            cout << a << "." << endl;
            break;
        }
        cout << a << ",";
        c = a + b;
        a = b;
        b = c;
        i++;
    }
}