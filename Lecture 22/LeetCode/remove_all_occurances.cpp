// 1910. Remove All Occurrences of a Substring

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,part;
    cout << "Enter String: ";
    getline(cin,s);

    cout << "Enter part: ";
    cin >> part;

    int t=part.length();
    int counter = 1;
    while(counter == 1)
    {
        counter = 0;
        int l=s.length();
        if(t > l)
            break;
        for(int i=0; i<(l-t+1); i++)
        {
            if(s[i] == part[0])
            {
                string w = s.substr(i,t);
                cout << "W: " << w << endl;
                if(w == part)
                {
                    string str = s.substr(0,i);
                    cout << "First Part: " << str << endl;
                    str.append(s.substr(i+t,l-i-t));
                    cout << "Second Part: " <<  str << endl;
                    s = str;
                    counter = 1;
                    break;
                }
            }
        }
    }

    // SECOND SOLUTION
    // while(s.length()!=0 && (s.find(part) < s.length()))
    // {
    //     s.erase(s.find(part),part.length());
    // }
    // return s;

    cout << "Final Result: " << s << endl;

    return 0;
}