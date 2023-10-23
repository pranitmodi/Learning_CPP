#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int i = 65;
    char ch = i;
    cout << ch << endl;
    ch = ch + 25;
    cout << ch << endl;

    char ch2 = '6';
    if(ch2 >= 48 && ch2 <= 57)
        cout << "Yes, It is a number: " << ch2 << endl;
    return 0;
}