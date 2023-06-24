#include <iostream>
using namespace std;
void printArray(int arr[])
{
    for(int i=0; i<5; i++)
    {
        cout << arr[i] << " "; // 24 is all thats printed
    }
    cout << endl;
}
int main()
{
    int arr1[100] = {0};
    cout << "arr1[0]= " << arr1[0] << endl;

    int arr2[5];
    fill_n(arr2, 5, 24);
    for(int i=0; i<5; i++)
    {
        cout << arr2[i] << " "; // 24 is all thats printed
    }

    cout << endl;

    int arr3[5] = {1};
    for(int i=0; i<5; i++)
    {
        cout << arr3[i] << " "; // 1 will be printed only for arr3[0]
    }

    cout << endl;

    printArray(arr2);

    return 0;
}