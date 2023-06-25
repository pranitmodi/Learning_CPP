#include <bits/stdc++.h>
using namespace std;
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



    cout << "Sorted Array: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}