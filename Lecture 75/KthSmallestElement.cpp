#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        
        priority_queue<int> q;
        int i = l;
        int j = 0;
        while(i<=r)
        {
            if(j<k)
                q.push(arr[i]);
            else
            {
                if(q.top() > arr[i])
                {
                    q.pop();
                    q.push(arr[i]);
                }
            }
            j++;
            i++;
        }
        
        return q.top();
    }
};