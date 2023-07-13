#include <bits/stdc++.h> 
using namespace std;
int main()
{
    deque<int> d;
    d.push_front(45);
    d.pop_back();
    cout << d.empty() << endl;
    d.push_back(45);
    cout << d.size() << endl;
    d.pop_front();
    cout << d.size() << endl;

    return 0;
}