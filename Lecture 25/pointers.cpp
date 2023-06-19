#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num=5;
    cout << "Address of num is: " << &num << endl; //0x61ff04

    int *p = &num;
    cout << "Printing through pointer: " << *p << endl; //5

    cout << "Printing pointer without star? - " << p << endl; //0x61ff04

    int *ptr = 0;
    // cout << *ptr << endl; // Nothing will return because such address does not exist

    *p = (*p) * 5;
    cout << *p << endl; //25
    cout << num << endl; //25

    cout << "Before p: " << p << endl; //0x61ff04
    p = p + 1;
    cout << "After p: " << p << endl; //0x61ff08

    int arr[] = {1,2,3,4,5};
    int *t = arr + 1; //2
    cout << "*t: " << *t << endl;

    return 0;
}