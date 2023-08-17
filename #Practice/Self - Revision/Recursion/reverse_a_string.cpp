#include <bits/stdc++.h>
using namespace std;
void reverse(int s, int e, string &str)
{
    if(s > e)
        return;

    swap(str[s++],str[e--]);
    reverse(s,e,str);
}
int main()
{
    string str = "pranit modi_%^*&";
    reverse(0,str.length()-1,str);
    cout << "Reverse String: " << str << endl;
}   