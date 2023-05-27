// LeetCode
// 724. Find Pivot Index

// Given an array of integers nums, calculate the pivot index of this array.
// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
// Return the leftmost pivot index. If no such index exists, return -1.

#include <bits/stdc++.h>
using namespace std;
// For input of the elements
int inputArray(int a[])
{
    cout << "Enter the number of elements: " << endl;
    int size;
    cin >> size;

    cout << "Enter elements: " << endl;
    for(int i=0; i<size; i++)
    {
        cin >> a[i];
    }
    return size;
}
//For printing the array elements
void printArray(int a[], int size)
{
    cout << "Array elements are: " << endl;
    for(int i=0; i<size; i++)
    {
        cout << a[i] <<" ";
    }
    cout << endl;
}
int main()
{
    int nums[20];
    int n=inputArray(nums);
    int sum=0;
    for(int i =0;i<n;i++)
    {
        sum=sum+nums[i];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        sum=sum-nums[i];
        if(sum == ans){
            cout << "Pivot Index: "<< i;
        }
           ans=ans+nums[i];
    }
    cout << "Pivot Index: "<< -1;

    return 0;
}