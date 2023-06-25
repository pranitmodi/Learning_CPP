// 78. Subsets
// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.
#include<bits/stdc++.h>
using namespace std;
void SubSets(vector <int> nums, vector <int> output, int i, vector <vector<int>>& ans)
{
    if(i>=nums.size())
    {
        ans.push_back(output);
        return;
    }

    int element = nums[i++];

    // exclude
    SubSets(nums, output, i, ans);

    // include
    output.push_back(element);
    SubSets(nums, output, i, ans);
}
int main()
{
    vector <vector<int>> ans;
    vector <int> nums;
    vector <int> output;
    int i = 0;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter elements: " << endl;
    int a;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        nums.push_back(a);
    }

    SubSets(nums, output, i, ans);

    // Printing of 2D Vector
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }    
        cout << endl;
    }

    return 0;
}