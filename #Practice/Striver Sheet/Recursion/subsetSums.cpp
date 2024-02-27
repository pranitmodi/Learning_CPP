// gfg
#include <bits/stdc++.h>
using namespace std;
void solve(int i, vector<int> arr, int sum, vector<int> &ans)
{
    if(i == arr.size())
    {
        ans.push_back(sum);
        return;
    }
    
    solve(i+1,arr,sum,ans);
    sum += arr[i];
    solve(i+1,arr,sum,ans);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int> ans;
    solve(0,arr,0,ans);
    sort(ans.begin(),ans.end());
    return ans;
}