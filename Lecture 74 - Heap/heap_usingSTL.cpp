#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Max Heap" << endl;
    priority_queue<int> maxheap;
    maxheap.push(2);
    maxheap.push(8);
    maxheap.push(6);
    maxheap.push(1);
    maxheap.push(5);

    cout << maxheap.top() << endl;
    maxheap.pop();
    cout << maxheap.top() << endl;
    maxheap.pop();
    cout << maxheap.top() << endl;
    maxheap.pop();

    cout << "Min Heap" << endl;
    priority_queue<int,vector<int>,greater<int>> minheap;
    minheap.push(2);
    minheap.push(6);
    minheap.push(8);
    minheap.push(3);
    minheap.push(1);

    cout << minheap.top() << endl;
    minheap.pop();
    cout << minheap.top() << endl;
    minheap.pop();
    cout << minheap.top() << endl;
    minheap.pop();
}