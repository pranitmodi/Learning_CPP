#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    string w = "";

    int n1 = n;
    while(n1 != 0)
    {
        int d = n1&1;
        if(d)
            w = "1" + w;
        else
            w = "0" + w; 

        n1 = n1 >> 1;
    }

    cout << w << endl;
    int b = stoi(w);
    cout << "Binary of the number is: " << b << endl;

    return 0;
}