// 344. Reverse String

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<char> s = {'o','k','a','y'};

    int st = 0;
    int e = s.size()-1;
    while(st<e)
    {
        swap(s[st++],s[e--]);
    }

    cout << "Reverse: ";
    for(int i:s)
    {
        cout << (char)i << " ";
    }
    cout << endl;
}