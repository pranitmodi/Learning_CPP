#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vec1;
    vector<int> vec2 = {1,2,3,4};
    vector<int> vec3(3,0); // (size of the vector, default value)

    cout << vec2[3] << endl;
    cout << sizeof(vec3) << endl; // 24 bytes - include padding and other things, thus not exact
    cout << vec3.size() << endl; // 3 - length of the vector

    cout << "All the elements: ";
    // ForEach Loop
    for(int i:vec2) { // 'i' will contain the vector elements
        cout << i << " ";
    }
    cout << endl;
}