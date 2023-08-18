#include <bits/stdc++.h>
using namespace std;
void subsets(vector<int> &arr,vector<int> output, int i, vector<vector<int>> &ans)
{
    if(i >= arr.size())
    {
        ans.push_back(output);
        return;
    }

    int ele = arr[i++];
    subsets(arr,output,i,ans);
    output.push_back(ele);
    subsets(arr,output,i,ans);
}
int main()
{
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    vector<int> output;
    subsets(arr,output,0,ans);
    cout << "Ans: " << endl;
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}