#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        priority_queue<pair<int, int> > heap;
     
        for (int i = 0; i < k; i++)
            heap.push({ arr[i], i });
    
        ans.push_back(heap.top().first);
     

        for (int i = k; i < n; i++) 
        {
            heap.push({ arr[i], i });
     
            while (heap.top().second <= i - k)
                heap.pop();

            ans.push_back(heap.top().first);
        }
     
        return ans;
    }
};