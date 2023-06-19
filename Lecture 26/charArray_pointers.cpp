#include<bits/stdc++.h>
using namespace std;
int main()
{
    char ch[6] = "abcde";
    char *c = &ch[0];

    cout << "c: " << c << endl; //abcde
    cout << "ch: " << ch << endl; //abcde

    char temp = 'a';
    char *q = &temp;

    cout << "Address of ch: " << &ch << endl; //0x61ff02
    cout << "Address of temp: " << &temp << endl; //aabcde

    cout << "q: " << q << endl; //aabcde - prints all until it finds a null character

    return 0;
}