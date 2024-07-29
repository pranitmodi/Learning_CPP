#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    n = abs(n);

    long binary = 0;
    int c = 0;
    while(n != 0)
    {
        if(n&1) 
        {
            double d = pow(10,c);
            binary = d + binary;
        }
        c++;
        n = n>>1;
    }

    cout << "Binary: " << binary << endl;

    // Compliment
    long b2 = binary;
    long comp = 0;
    int w = 0;
    while(b2 != 0)
    {
        int d = b2%10;
        if(d == 0)
        {
            double p = pow(10,w);
            comp = p + comp;
        }
        w++;
        b2 = b2/10;
    }
    
    w=0;
    long comp1 = comp;
    while(comp1 != 0)
    {
        w++;
        comp1 = comp1/10;
    }

    cout << "Complimentary: ";
    for(int i=1; i<=(32-c); i++)
    {
        cout << "1";
        if(i%8 == 0)
            cout << " ";
    }
    for(int i=1; i<=(c-w); i++)
    {
        cout << "0";
    }
    cout << comp << endl;

    // Adding One
    long two = comp;
    if(comp&1 == 0)
        two = two + 1;
    else
    {
        int g=0;
        int d = comp%10;
        while(d != 0)
        {
            comp = comp/10;
            g++;
            d = comp%10;
        }
        two = comp+1;
        double t = pow(10,g);
        two = two * t;
        if(g == w)
            w++;
    }

    cout << "Two's Compliment: ";
    for(int i=1; i<=(32-c); i++)
    {
        cout << "1";
        if(i%8 == 0)
            cout << " ";
    }
    for(int i=1; i<=(c-w); i++)
    {
        cout << "0";
    }
    cout << two << endl;


    return 0;
}
