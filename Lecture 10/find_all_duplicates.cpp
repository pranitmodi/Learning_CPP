#include <bits/stdc++.h>
using namespace std;
int main()        
{
    int arr[20];
    int size;
    cout << "Enter Size: " << endl;
    cin >> size;

    cout << "Enter elements: " << endl;
    for(int i=0; i<size; i++)
    {
        cin >> arr[i];
    }

    cout << "Array eleemnts: " << endl;
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for(int i=0; i<size; i++)
    {
        int t=arr[i];
        int p=i;
        for(int j=i+1; j<size; j++)
        {
            if(arr[j]<t)
            {
                t = arr[j];
                p=j;
            }
        }
        arr[p] = arr[i];
        arr[i] = t;
    }

    cout << "Sorted Array elements: " << endl;
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int ans[20];
    int c=0;
    for(int i=0; i<size-1; i++)
    {
        if(arr[i] == arr[i+1])
        {
            ans[c] = arr[i];
            c++;
            i++;
        }
    }

    cout << "Duplicated elements: " << endl;
    for(int i=0; i<c; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}