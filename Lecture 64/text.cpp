#include <bits/stdc++.h>
using namespace std;
int main()
{
    // vector<int> v = { 0, 52, 56, 1, 2, 3, 4, 5 };
    // cout << "Result: ";
    // for(auto i:v)
    //     cout << i << " ";
    // cout << endl;

    map<int,int> maps;
    maps[2] = 45;
    maps[1] = 23;
    maps[6] = 9;
    maps[67] = 45;

    // Thus, keys are arranged in assecding order
    for(auto i:maps)
    {
        cout << i.first << " - " << i.second << endl;
    }


    return 0;
}