#include <bits/stdc++.h>
using namespace std;
int sum(int arr[], int n)
{
    if(n == 0)
        return 0;
    
    cout << n << endl;
    return(arr[n-1] + sum(arr,--n));
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    cout << "Sum: " << sum(arr,8);
}