#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {-1,-100,3,99};
    int k = 2;

    // TIME LIMIT EXCEEDED
    // for(int i=1; i<=k; i++)
    // {
    //     int res = nums[l];

    //     for(int j=l-1; j>=0; j--)
    //     {
    //         nums[j+1] = nums[j];
    //     }

    //     nums[0] = res;
    // }

    int l = nums.size();
    int arr[200000];

    while(k>l)
    {
        k = k - l;
    }

    // storing the last part
    int d = 0;
    for(int i=l-k; i<l; i++)
    {
        arr[d++] = nums[i];
    }

    // shifting the first part
    int w = l-1;
    for(int i=l-k-1; i>=0; i--)
    {
        nums[w--] = nums[i];
    }

    // fixing the first part
    for(int i=0; i<k; i++)
    {
        nums[i] = arr[i];
    }

    cout << "Output: ";
    for(int i=0;i<l;i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}