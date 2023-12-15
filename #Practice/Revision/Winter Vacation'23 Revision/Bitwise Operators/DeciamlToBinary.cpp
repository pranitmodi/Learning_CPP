#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    string s = "";
    if(n < 0)
    {
        n = abs(n);

        while(n != 0)
        {
            s = to_string(!(n&1)) + s;
            n = n>>1;
        }


        int c = 1;
        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i] == '0')
            {
                s[i] = '1';
                c = 0;
                break;
            }
            else
            {
                s[i] = '0';
            }
        }

        if(c == 1)
        {
            s = "1" + s;
        }
    }
    else
    {
        while(n != 0)
        {
            s = to_string(n&1) + s;
            n = n>>1;
        }
    }

    cout << "Binary: " << s << endl;
}