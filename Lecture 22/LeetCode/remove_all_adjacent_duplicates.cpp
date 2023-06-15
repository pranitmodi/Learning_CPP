#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    // Faster Solution
    // string temp = "";
    // for(int i =0; i<s.length(); i++)
    // {
    //     temp.push_back(s[i]);
    //     if(temp.size() >= 2 && temp[temp.length() -1] == temp[temp.length() -2])
    //     {
    //     temp.pop_back();
    //     temp.pop_back(); 
    //     }
    // }
    // return temp;

    int c = 1;
    while(c == 1)
    {
        c = 0;
        if(s.length() == 0)
            cout << "Done?" << endl;
        for(int i=0; i<(s.length()-1); i++)
        {
            cout << s[i] << "i:" << i << endl;
            if(s[i] == s[i+1])
            {
                c=1;
                s.erase(i,2);
                cout << "New: " << s << endl;
                break;
            }
        }
    }

    cout << "Final: " << s << endl;

    return 0;
}