#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5,7,8};

    // ALL ARE SAME
    cout << "arr: " << arr << endl; //0x61fef4
    cout << "&arr: " << &arr << endl; //0x61fef4
    cout << "&arr[0]: " << &arr[0] << endl; //0x61fef4

    cout << endl;
    int *p = arr;
    cout << "p: " << p << "  *p: " << *p << endl;
    cout << "Size of p: " << sizeof(p) << endl;
    cout << "Size of &p: " << sizeof(&p) << endl;
    cout << "Size of arr: " << sizeof(arr) << endl; //28
    cout << "Size of *p: " << sizeof(*p) << endl;
    cout << endl;

    p = p + 1;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl; // prints nothig
    cout << "arr[1]: " << arr[1] << endl;


    cout << endl; 
    cout << "*arr: " << *arr << endl; //1

    cout << "*arr + 1 :" << *arr + 30 << endl; //1+30 = 31
    cout << "*(arr + 1) :" << *(arr + 1) << endl; //2

    // arr[i] = i[arr]; 
    cout << "3[arr]: " << 3[arr] << endl; //4

    return 0;
}