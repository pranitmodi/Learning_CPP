// 283. Move Zeroes

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums;
    int e;
    cout << "Number of elements: ";
    cin >> e;

    cout << endl << "Enter elements: " << endl;
    for(int i=0; i<e; i++)
    {
        int r;
        cin >> r;
        nums.push_back(r);
    }

    int i=0;
    int j=0;
    while(i<e)
    {
        if(nums[i] != 0)
        {
            swap(nums[j],nums[i]);
            j++;
        }
        i++;
    }

    cout << "Output: ";
    for(int i=0; i<e; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
