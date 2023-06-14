#include <bits/stdc++.h>
using namespace std;
int main()
{
    char str[20];
    cout << "Enter String:";
    cin >> str;

    // Length
    int j=0;
    while(str[j] != '\0')
        j++;
    j--;
    int i = 0;

    int counter = 0;
    while(i<=j)
    {
        if(str[i++] != str[j--])
        {
            counter++;
            break;
        }
    }

    if(counter == 0)
        cout << "Palindrome!" << endl;
    else
        cout << "Not a Palindrome" << endl;

    return 0;
}