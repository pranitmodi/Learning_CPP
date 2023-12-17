#include <bits/stdc++.h>
using namespace std;
// Equally good solution using Binary Search
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size() - 1;
        while (high - low >= k) {
            int diff1 = x - arr[low];
            int diff2 = arr[high] - x;
            if (diff1 > diff2) {
                low++;
            }
            else {
                high--;
            }
        }
        vector<int> ans;
        for (int i = low; i <= high; i++) {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};


// My Solution
// Intutuin - the middle element of the ans vector should be <= x
bool check(int i, int n)
{
    if(i>=0 && i<n)
        return true;
    return false;
}
vector<int> findClosestElements(vector<int>& arr, int k, int x) 
{
    int i = 0;
    for(i=0; i<arr.size(); i++)
    {
        if(arr[i] >= x)
            break;
    }    

    vector<int> ans;
    int p = 0;
    int q = 1;
    int c = 0;
    while(c<k)
    {
        if(check((i+p),arr.size()) && check((i-q),arr.size()))
        {
            int a = abs(arr[i+p] - x);
            int b = abs(arr[i-q] - x);
            if(a < b)
            {
                ans.push_back(arr[i+p]);
                c++;
                p++;
            }
            else
            {
                ans.push_back(arr[i-q]);
                c++;
                q++;
            }
        }
        else
        {
            if(check((i+p),arr.size()))
            {
                ans.push_back(arr[i+p]);
                c++;
                p++;
            }

            if(check((i-q),arr.size()))
            {
                ans.push_back(arr[i-q]);
                c++;
                q++;
            }
        }
    }

    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    vector<int> arr = {0,0,1,2,3,3,4,7,7,8};
    vector<int> ans = findClosestElements(arr,3,5);

    cout << "ANS: " << endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

