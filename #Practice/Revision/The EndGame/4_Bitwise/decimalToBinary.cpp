#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter a decimal number:";
    cin >> n;

    string str = "";
    while(n>0)
    {
        if(n%2 == 0)
            str = "0" + str;
        else
            str = "1" + str;

        n = n/2;
    }

    cout << "Binary will be: " << str << endl;
}