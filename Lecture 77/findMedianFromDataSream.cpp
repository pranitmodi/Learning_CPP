// 295 - HARD
#include <bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    MedianFinder() {}

    void addNum(int num) {
        if (maxHeap.empty() || maxHeap.top() > num) 
			maxHeap.push(num);
        else 
			minHeap.push(num);

		if (maxHeap.size() > minHeap.size() + 1) 
        {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		} 
        else if (minHeap.size() > maxHeap.size() + 1) 
        {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
    }

    double findMedian() {
        int n1 = minHeap.size();
        int n2 = maxHeap.size();

        if(n2 == 0)
            return 0;

        if (n1 == n2)
            return (minHeap.top() + maxHeap.top()) / 2.0;
        else if (n1 > n2)
            return minHeap.top();
        else
            return maxHeap.top();
    }
};
