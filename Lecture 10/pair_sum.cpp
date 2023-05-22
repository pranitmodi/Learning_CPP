#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum;
    cout << "Enter the sum value: " << endl;
    cin >> sum;

    int arr[20];
    int s1;
    cout << "Enter the size: " << endl;
    cin >> s1;
 

    cout << "Enter the elements of the array: " << endl;
    for(int i=0; i<s1; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> ans;
    for(int i=0; i<s1; i++)
    {
        for(int j=i+1; j<s1; j++)
        {
            if(arr[i] + arr[j] == sum)
            {
                vector<int> temp;
                temp.push_back(min(arr[i],arr[j]));
                temp.push_back(max(arr[i],arr[j]));
                ans.push_back(temp);
            }
        }
    }

    sort(ans.begin(),ans.end());
    int l=ans.size();
    cout << "Result :" << endl;
    for(int i=0; i<l; i++)
    {
        cout << ans[i][0] << "," << ans[i][1] << " ";
    }

    cout << endl;

    return 0;
}