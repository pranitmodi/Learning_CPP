#include <bits/stdc++.h>
using namespace std;
void print(int *a, int b = 2) // or -> (int a[], int b = 2)
{
    cout << a[b] << endl;
}
int main()
{
    int arr[] = {1,2,3,5};
    print(arr,1); //2
    print(arr); //3
}