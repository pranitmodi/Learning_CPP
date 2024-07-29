#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(6);
    v.push_back(2);

    vector<vector<int>> vv;
    vv.push_back(v);

    sort(v.begin(),v.end());

    vv.push_back(v);

    sort(vv.begin(),vv.end());

    // Directly accessing vector elements
    for(int i:v)
    {
        cout << i << " ";
    }
    cout << endl;

    for(vector<int> i:vv)
    {
        for(int j:i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    auto i = find(v.begin(),v.end(),16);
    if(i != v.end())
    {
        cout << "index: " << distance(v.begin(),i)-1 << endl;
    }
    else
        cout << "Not Found!" << endl;
}