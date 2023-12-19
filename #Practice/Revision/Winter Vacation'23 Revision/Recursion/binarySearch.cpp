#include <bits/stdc++.h>
using namespace std;
int binaryS(int s, int e, int arr[], int key)
{
    if(s>e)
        return -1;

    int mid = s + (e-s)/2;

    if(arr[mid] == key)
        return mid;
    else if(arr[mid] > key)
        return(binaryS(s,mid-1,arr,key));
    else
        return(binaryS(mid+1,e,arr,key));
}
int main()
{
    int arr1[] = {1,2,3,4,5,6,8,9,2567};
    int arr2[] = {2,5,7,9,23,8756,22346};

    cout << binaryS(0,9-1,arr1,2567) << endl;
    cout << binaryS(0,9-1,arr1,257) << endl;
    cout << binaryS(0,7-1,arr2,2) << endl;
}