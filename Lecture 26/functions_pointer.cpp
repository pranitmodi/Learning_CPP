#include <bits/stdc++.h>
using namespace std;
void update(int *p)
{
    *p = *p + 1;
    cout << "Value inside: " << *p << endl;
    p = p + 1;
    cout << "Address inside: " << p << endl;
}
int getSum(int *arr) //also works for (int arr[])
{
    cout << "Size of sizeof(arr) INSIDE: " << sizeof(arr) << endl; //returns the pointer size i.e. 4
    int sum = 0;
    for(int i=0; i<5; i++)
    {
        sum = sum + *(arr + i);
    }
    return sum;
}
int main()
{
    int a = 89;
    int *p = &a;

    cout << "Value before: " << *p << endl;
    cout << "Address before: " << p << endl;
    update(p);
    cout << "Value after: " << *p << endl;
    cout << "Address after: " << p << endl;
    cout << endl;

    int arr[5] = {1,2,3,4,5};
    int sum = getSum(arr);

    cout << "Size of sizeof(arr) OUTSIDE: " << sizeof(arr) << endl; //20
    cout << "Sum: " << sum << endl;

    return 0;
}