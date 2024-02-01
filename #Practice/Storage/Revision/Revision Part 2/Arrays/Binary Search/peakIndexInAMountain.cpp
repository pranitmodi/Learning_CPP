#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5,3,2,1};
    int n = sizeof(arr)/sizeof(int);

    int s = 0;
    int e = n-1;

    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(arr[mid+1] > arr[mid])
            s = mid + 1;
        else
            e = mid - 1;
    }

    cout << s << " " << e << endl;

    return 0;
}