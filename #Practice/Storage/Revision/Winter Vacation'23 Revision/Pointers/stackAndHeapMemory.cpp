// Stack
// memory gets allocated during compile time
// Static memory allocation

// Heap
// Dynamic memory allocation
// memory allocation happens during runtime
// to use heap - we use "new" keyword and we store the address

#include <bits/stdc++.h>
using namespace std;
int main()
{
    char *ch = new char;
    int *arr = new int[10];

    *ch = 'a';
    cout << ch << endl;

    delete ch;
    delete []arr;
}