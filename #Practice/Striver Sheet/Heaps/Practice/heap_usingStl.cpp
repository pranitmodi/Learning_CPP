#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;

    maxHeap.push(1);
    maxHeap.push(5);
    maxHeap.push(2);
    maxHeap.push(3);
    maxHeap.push(7);
    maxHeap.push(1);
    maxHeap.push(2);

    cout << maxHeap.top() << endl;
    maxHeap.pop();
    cout << maxHeap.top() << endl;
}