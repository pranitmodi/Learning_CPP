#include <bits/stdc++.h>
using namespace std;
int position(vector<int>& nums, int s, int e)
{
    int ele = nums[s];
    int count = 0;
    for(int i=s+1; i<=e; i++)
    {
        if(nums[i]<=ele)
            count++;
    }

    swap(nums[s+count],nums[s]);
    int pos = s+count;

    int i = 0;
    int j = pos + 1;
    while(i<pos && j<=e)
    {
        while(nums[j]>ele)
            j--;
        
        while(nums[i]<ele)
            i++;

        swap(nums[i],nums[j]);
    }

    return pos;
}
void quickSort(vector<int>& nums, int s, int e)
{
    if(s>=e)
        return;


    int pos = position(nums,s,e);

    quickSort(nums,s,pos-1);
    quickSort(nums,pos+1,e);
}
int main()
{
    vector <int> nums;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter elements:" << endl;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    quickSort(nums,0,nums.size()-1);

    cout << "Sorted Array: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}