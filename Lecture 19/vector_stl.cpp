#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    vector <int> v;

    cout << "No element" << endl;
    cout << "Capacity - " << v.capacity() << endl; //0
    cout << "Size - " << v.size() << endl;
    v.push_back(45);
    cout << "One element" << endl;
    cout << "Capacity - " << v.capacity() << endl; //1
    cout << "Size - " << v.size() << endl;
    v.push_back(4);
    cout << "Two element" << endl;
    cout << "Capacity - " << v.capacity() << endl; //2 = 1*2
    cout << "Size - " << v.size() << endl;
    v.push_back(5);
    cout << "Three element" << endl;
    cout << "Capacity - " << v.capacity() << endl; //4 - keeps on doubling as the element increses and no more space
    cout << "Size - " << v.size() << endl;
    v.push_back(7);
    cout << "Fourth element" << endl;
    cout << "Capacity - " << v.capacity() << endl; //4
    cout << "Size - " << v.size() << endl;
    v.push_back(4);
    cout << "Fifth element" << endl;
    cout << "Capacity - " << v.capacity() << endl; //4
    cout << "Size - " << v.size() << endl;

    // Sorting of Vector
    sort(v.begin(),v.end());

    // Better way to access vector elements
    cout << "Vector Elements: ";
    for(int i:v)
    {
        cout << i <<" ";
    }
    cout << endl;

    vector <int> a(6,2); // 2 2 2 2 2 2
    cout << "A elements: ";
    for(int i:a)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << a.at(0); // you can use .at() for specific element

    return 0;
}