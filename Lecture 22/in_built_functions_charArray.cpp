#include <bits/stdc++.h>
using namespace std;
int main()
{
    char ch1[20];
    char ch2[20];
    cout << "Enter the first string: ";
    cin >> ch1;
    cout << "Enter the second string: ";
    cin >> ch2;

    int l1 = strlen(ch1); //LENGTH
    cout << "Length of the first string: " << l1 << endl;

    cout << "Are the equal?" << strcmp(ch1,ch2) << endl; //COMPARE
    strcpy(ch1,ch2); //COPY
    cout << "Are the equal now?" << strcmp(ch1,ch2) << endl;

    // String
    string s1 = "pkau";
    string s2 = "sfwew";
    if(s1 == s2)
    {
        cout << "same" << endl;
    }
    else
        cout << "Not Same" << endl;

    return 0;
}