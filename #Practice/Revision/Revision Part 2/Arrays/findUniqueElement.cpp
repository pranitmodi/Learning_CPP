#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5,6,5,4,1,2,3};
    int n = sizeof(arr)/sizeof(int);

    int ans = 0;
    for(int i=0; i<n; i++)
    {
        ans = ans^arr[i];
    }

    cout << "Answer: " << ans << endl;

    return 0;
}