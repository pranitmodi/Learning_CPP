// 1207. Unique Number of Occurrences
// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[30];

    int s;
    cout << "Enter the number of elements: " << endl;
    cin >> s;

    cout << "Enter elements: " << endl;
    for(int i=0; i<s; i++)
    {
        cin >> arr[i];
    }

    int size = sizeof(arr)/sizeof(int);

    cout << "Array elements: " << endl;
    for(int i=0; i<s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Sorting the array
    for(int i=0; i<s; i++)
    {
        int t=arr[i];
        int p=i;
        for(int j=i+1; j<s; j++)
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
    for(int i=0; i<s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    vector<int> ans; //Another vector to store the frequency of the elements

    int i=0;
    while(i < s)
    {
        int count = 1;  
        for(int j=i+1; j<s; j++)
        {
            if(arr[i] == arr[j])
            {
                count++; //while same element
            }
            else
            {
                break; //as soon as different element
            }
        }
        ans.push_back(count);
        i=i+count; //to the next unique element
    }

    size = ans.size();
    sort(ans.begin(),ans.end()); // sorting the vector
    for(int i=0; i<size-1; i++)
    {
        if(ans[i] == ans[i+1]) // if two elements are same ie two numbers in the original array have the same frequency
        {
            cout << "false";
            return 0;
        }
    }
    cout << "true"; // if false hasn't been returned till now then true
    return 0;
}