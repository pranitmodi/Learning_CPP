#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void heapify(vector<int> &ans, int i, int n)
    {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        if(left<=n && ans[left] > ans[largest])
            largest = left;
        if(right<=n && ans[right] > ans[largest])
            largest = right;
            
        if(largest != i)
        {
            swap(ans[i],ans[largest]);
            heapify(ans,largest,n);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) 
    {
        vector<int> ans;
        
        for(int i=0; i<n; i++)
            ans.push_back(a[i]);
        
        for(int i=0; i<m; i++)
            ans.push_back(b[i]);
        
        int w = ans.size();
        for(int i=(w/2)-1; i>=0; i--)
            heapify(ans,i,w-1); // as elements are till w-1 index.
        
        return ans;
    }
};