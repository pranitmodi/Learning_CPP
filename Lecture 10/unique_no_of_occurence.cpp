// 1207. Unique Number of Occurrences
// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[30];

    cout << "Enter elements: " << endl;
    for(int i=0; i<20; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans;
    int size = arr.size();
    sort(arr.begin(),arr.end());
    int i=0;
    while(i < size)
    {
        int count = 1;
        for(int j=i+1; j<size; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        ans.push_back(count);
        i=i+count;
    }
    size = ans.size();
    sort(ans.begin(),ans.end());
    for(int i=0; i<size-1; i++)
    {
        if(ans[i] == ans[i+1])
            cout <<  false;
    }
    cout << true;
}