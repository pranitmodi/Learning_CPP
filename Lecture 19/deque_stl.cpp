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

    
    return 0;
}