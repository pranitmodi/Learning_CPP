#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of digits: ";
    cin >> n;

    int arr[20];
    cout << "Enter elements:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the sum needed: ";
    int target;
    cin >> target;

    map<int,int> mapping;
    for(int i=0; i<n; i++)
    {
        mapping[target-arr[i]] = arr[i];
    }

    cout << "Pair: " << endl;
    for(int i=n-1; i>=0; i--)
    {
        int left = target - arr[i];
        if(mapping.find(left) != mapping.end())
        {
            cout << arr[i] << " , " << mapping[arr[i]] << endl;
        }
    }

    return 0;
}