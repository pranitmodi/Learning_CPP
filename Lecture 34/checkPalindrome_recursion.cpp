#include <bits/stdc++.h>
using namespace std;
bool checkPalindrome(string &str, int i)
{
    int j = str.length() - i - 1;

    if(i>j)
        return true;

    if(str[i] != str[j])
        return false;
    return(checkPalindrome(str,++i));
}
int main()
{
    string str;
    cout << "Enter the String: ";
    cin >> str;

    bool ans = checkPalindrome(str, 0);

    cout << "Palindrome? : ";
    if(ans)
        cout << "YES!" << endl;
    else
        cout << "No" << endl;

    return 0;
}