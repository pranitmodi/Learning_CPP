#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print(vector<int> v)
{
    cout << "Vector: ";
    for(int i:v)
        cout << i << " ";
    cout << endl;
}
int main()
{
    vector <int> v;
    v.push_back(3);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);

    print(v);

    // Binary Search - FOR SORTED ARRAY
    cout << "Finding 9 - " << binary_search(v.begin(), v.end(), 9) << endl; // 1
    cout << "Finding 4 - " << binary_search(v.begin(), v.end(), 4) << endl; // 0

    // Sorting
    sort(v.begin(),v.end());
    print(v);

    // Lower and Upper Bound
    cout << "Lower Bound of 9: " << lower_bound(v.begin(),v.end(),9) - v.begin() << endl;
    cout << "Upper Bound of 2: " << upper_bound(v.begin(),v.end(),2) - v.begin() << endl;

    // Max, Min AND Swap
    int a = 34;
    int b = 56;
    cout << "Max: " << max(a, b) << endl << "Min: " << min(a,b) << endl;
    cout << "a: " << a << " -> a: ";
    swap(a,b);
    cout << a << endl;

    // Reversing
    string str = "Hello, My name is Pranit.";
    cout << str << endl;
    reverse(str.begin(),str.end());
    cout << str << endl;
    cout << a << endl;

    reverse(v.begin(),v.end());
    print(v);

    // Rotation
    cout << "Rotating two times -> " << endl;s
    rotate(v.begin(),v.begin()+2,v.end());
    print(v);

    return 0;
}