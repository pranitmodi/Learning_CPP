#include <iostream>
using namespace std;
int main()
{
    int arr1[100] = {0};
    cout << "arr1[0]= " << arr1[0] << endl;

    int arr2[5];
    // int arr2[5] = {1}; -> does not works
    fill_n(arr2, 5, 24);
    for(int i=0; i<5; i++)
    {
        cout << arr2[i] << " "; // 24 is all thats printed
    }
    return 0;
}