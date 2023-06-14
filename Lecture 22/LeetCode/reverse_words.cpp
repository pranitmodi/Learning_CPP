#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cout << "Enter the string: ";
    getline(cin, str);

    cout << "Original String: " << str << endl;

    int l = str.length();

    int s = 0;

    for(int i=0; i<l; i++)
    {
        if(str[i] == ' ')
        {
            for(int j=s,e=i-1; j<e; j++,e--)
            {
                swap(str[j],str[e]);
            }
            s = i+1;
        }
    }
    for(int i=s,j=l-1; i<j; i++,j--)
    {
        swap(str[i],str[j]);
    }

    cout << "Reverse Words: " << str << endl;

    return 0;
}