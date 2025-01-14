#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(23);
    v.push_back(35);
    v.push_back(56);
    v.pop_back();

    cout << "All the elements: ";
    for(int val:v) {
        cout << val << " ";
    }
    cout << endl;

    cout << v.front() << endl;
    cout << v.back() << endl;
    cout << v.at(1) << endl; //value at a particular index
}