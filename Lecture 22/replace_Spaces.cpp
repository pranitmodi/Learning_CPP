#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cout << "Enter a String: ";
    getline(cin,str);

    string temp = "";

    int l=str.length();
    cout << "String after replaced spaces: ";
    for(int i=0; i<l; i++)
    {
        if(str[i] == ' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else
            temp.push_back(str[i]);
    }
    cout << temp << endl;

    return 0;
}