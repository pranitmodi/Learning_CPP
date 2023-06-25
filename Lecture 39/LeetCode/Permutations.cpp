// LeetCode
// 46. Permutations
#include <bits/stdc++.h>
using namespace std;
void permutations(vector <int> nums, int index, vector <vector <int>>& ans)
{
    if(index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int i=index; i<nums.size(); i++)
    {
        swap(nums[index],nums[i]);
        permutations(nums,index+1,ans);

        //backtracking
        swap(nums[index],nums[i]);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector <int> nums;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    vector <vector <int>> ans;
    int index = 0;
    permutations(nums,index,ans);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout << ans[i][j];
        }
        cout << " ";
    }
    cout << endl;

    return 0;
}