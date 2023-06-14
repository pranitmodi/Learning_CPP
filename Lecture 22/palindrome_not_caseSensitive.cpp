#include <bits/stdc++.h>
using namespace std;
char toLowerCase(char ch)
{
    if(ch>='A' && ch<='Z')
        return(ch - 'A' + 'a');
    else
        return(ch);
}
bool check(char ch)
{
    if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9'))
    {
        return true;
    }
    return false;
}
int main()
{
    char str[25]; //NO SPACES ALLOWED BECAUSE CHAR ARRAY
    cout << "Enter String:";
    cin >> str;

    // Length
    int j=0;
    while(str[j] != '\0')
    {
        str[j] = toLowerCase(str[j]);
        j++;
    }
    j--;

    cout << "Length: " << j << endl;
    int i = 0;

    int counter = 0;

    while(!check(str[i]))
    {
        i++;
    }
    while(!check(str[j]))
    {
        j--;
    }

    while(i<=j)
    {
        if(str[i++] != str[j--])
        {
            counter++;
            cout << str[i-1] << " " << str[j+1] << ":" << j+1 <<  endl;
        }
        while(!check(str[i]))
            i++;
        while(!check(str[j]))
            j--;
    }

    // cout << "To Lower Case: " << str << endl;

    if(counter == 0)
        cout << "Palindrome!" << endl;
    else
        cout << "Not a Palindrome" << endl;
    return 0;
}