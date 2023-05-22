#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr1[20];
    int arr2[20];
    int s1,s2;
    cout << "Enter the sizes: " << endl;
    cin >> s1;
    cin >> s2;

    cout << "Enter the elements for the first array: " << endl;
    for(int i=0; i<s1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter the elements for the second array: " << endl;
    for(int i=0; i<s2; i++)
    {
        cin >> arr2[i];
    }

    int m[20];
    int c=0;
    for(int i=0,j=0; i<s1 && j<s2; )
    {
        if(arr1[i] == arr2[j])
        {
            m[c] = arr1[i];
            i++;
            j++;
            c++;
        }
        else if(arr1[i] < arr2[j])
        {
            i++;
        }
        else if(arr1[i] > arr2[j])
        {
            j++;
        }
    }

    cout << "Result: " << endl;
    for(int i=0; i<c; i++)
    {
        cout << m[i] << " ";
    }
    cout << endl;
    return 0;
}