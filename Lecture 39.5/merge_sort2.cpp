#include <bits/stdc++.h>
using namespace std;
void merge(vector <int>& nums, int s, int e)
{
    int mid = s + (e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *a = new int[len1];
    int *b = new int[len2];

    int index = s;
    for(int i=0; i<len1; i++)
    {
        a[i] = nums[index++];
    }
    for(int i=0; i<len2; i++)
    {
        b[i] = nums[index++];
    }

    int i = 0;
    int j = 0;
    index = s;
    while(i<len1 && j<len2)
    {
        if(a[i] <= b[j])
        {
            nums[index++] = a[i++];
        }
        else
        {
            nums[index++] = b[j++];
        }
    }
    while(i<len1)
        nums[index++] = a[i++];
    while(j<len2)
        nums[index++] = b[j++];
}
void mergeSort(vector <int>& nums, int s, int e)
{
    if(s>=e)
        return;

    int mid = s + (e-s)/2;

    mergeSort(nums,s,mid);
    mergeSort(nums,mid+1,e);

    merge(nums,s,e);
}
int main()
{
    vector <int> nums;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    mergeSort(nums,0,nums.size()-1);

    cout << "Sorted Array: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}