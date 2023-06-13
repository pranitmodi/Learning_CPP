// LeetCode
// 88. Merge Sorted Array
#include <bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int n)
{
    for(int i = 0; i<n-1; i++)
    {
        int pos = i;
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] < arr[pos])
            {
                pos = j;
            }
        }
        swap(arr[pos], arr[i]);
    }
}
int main()
{
    // int nums1[] = {1,2,3,0,0,0};
    // int nums2[] = {2,5,6};
    // int n = 3, m = 3;

    int nums1[20];
    int nums2[20];

    // INPUT
    int n,m;
    cout << endl <<  "Enter m: ";
    cin >> m;
    cout << "Enter n: ";
    cin >> n;

    cout << "Input Element for nums1: " << endl;
    for(int i=0; i<m; i++)
    {
        cin >> nums1[i];
    }
    cout << "Input Element for nums2: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> nums2[i];
    }

    // SOLUTION
    int i = 0;
    int j = 0;
    if(n > 0 && m > 0)
    {
        while(i < m)
        {
            if(nums1[i] <= nums2[j])
            {
                i++;
            }
            else
            {
                swap(nums1[i], nums2[j]);
                i++;
                // sort(nums2.begin(),nums2.end()); // for vector
                selectionSort(nums2, n);
            }
        }
    
        while(i < (m+n))
        {
            swap(nums1[i], nums2[j]);
            i++;
            j++;
        }
    }
    else if(m == 0)
    {
        for(int i=0; i<n; i++)
        {
            nums1[i] = nums2[i];
        }
    }

    cout << "Output: ";
    for(int i=0; i<(m+n); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}