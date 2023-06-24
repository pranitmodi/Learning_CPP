#include <iostream>
using namespace std;
void AP()
{
    int n;
    cout << "Enter the nth place for AP: " << endl;
    cin >> n;
    cout << "Result: " << ((3*n) + 7);
}
void set_bits()
{
    int a,b;
    cout << "Enter the two integer values for set bits: " << endl;
    cin >> a >> b;
    int c=0;
    while(a!=0)
    {
        if(a&1)
            c++;
        a=a>>1;
    }
    while(b!=0)
    {
        if(b&1)
            c++;
        b=b>>1;
    }
    cout << "Result: " << c;
}
void Fib()
{
    int n;
    cout << "Enter the nth place for Fibonnaci: " << endl;
    cin >> n;
    int a = 0;
    int b = 1;
    if(n == 1)
    {
        cout << "Result: " << a;
        return;
    }
    if(n == 2)
    {
        cout << "Result: " << b;
        return;
    }
    for(int i=2; i<n; i++)
    {
        int c = a+b;
        a = b;
        b = c;
    }
    cout << "Result: " << b;
}
int main()
{
    int ch;
    cout << "Enter 1 for AP, 2 for a&b, 3 for Fibbonaci: " << endl;
    cin >> ch;

    switch(ch)
    {
        case 1: 
            AP();
            break;
        case 2: 
            set_bits();
            break;
        case 3:
            Fib();
            break;
        default: cout << "Invalid Input" << endl;
    }
    return 0;
}