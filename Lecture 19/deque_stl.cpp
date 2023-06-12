#include <bits/stdc++.h>
#include <deque>
using namespace std;
void print(deque<int> d)
{
    cout << "Deque elements: ";
    for(int i:d)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    // Dynamic, two-headed queue
    deque <int>d;

    d.push_back(2); // to enter from thr front
    d.push_front(4); // to enter from the back
    print(d); // 4 2

    d.pop_back(); // to remove the element from the back
    print(d);
    d.pop_front(); // to remove the element from the first
    print(d);

    d.push_front(1);
    d.push_front(2);
    d.push_front(3);
    print(d);
    cout << "Element at 0th index: " << d.at(0) << endl; // you can use .at() for specific element

    cout << "Empty? - " << d.empty() << endl; // return 0 - false - not empty

    d.erase(d.begin(), d.end()); // Erasing all the elements(starting position, ending position) - using d.begin() and d.end() only preferrably
    print(d);
    cout << "Empty? - " << d.empty() << endl; // returns true
    
    return 0;
}