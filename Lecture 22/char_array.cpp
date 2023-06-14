#include <bits/stdc++.h>
using namespace std;
int lengthChar(char name[])
{
    int i=0;
    while(name[i] != 0)
    {
        i++;
    }
    return i;
}
void reverseChar(char name[])
{
    int l = lengthChar(name);
    int i = 0;
    int j = l-1;
    while(i<j)
    {
        swap(name[i++],name[j--]);
    }
}
int main()
{
    char name[20];
    cout << "Enter your name: ";
    cin >> name;

    // name[3] = '\0';

    cout << "Your name is " << name << endl;
    cout << "Length: " << lengthChar(name) << endl;
    reverseChar(name);
    cout << "Reverse Name: " << name << endl;
    return 0;
}