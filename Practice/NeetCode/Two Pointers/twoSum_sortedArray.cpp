// LeetCode - 167
#include <bits/stdc++.h>
using namespace std;

// Approach 1 - O(n * log(n))
// int binarySearch(int s, int e, int target, vector<int>& numbers)
// {
//     if(s > e)
//         return -1;

//     int mid = s + (e-s)/2;
//     if(numbers[mid] == target)
//         return mid;
//     else if(numbers[mid] > target)
//     {
//         int f = binarySearch(s,mid-1,target,numbers);
//         if(f != -1)
//             return f;
//     }
//     else
//     {
//         int f = binarySearch(mid+1,e,target,numbers);
//         if(f != -1)
//             return f;
//     }
//     return -1;
// }
// vector<int> twoSum(vector<int>& numbers, int target) 
// {
//     vector<int> ans(2);
//     for(int i=0; i<numbers.size()-1; i++)
//     {
//         int find = target - numbers[i];
//         int val = binarySearch(i+1,numbers.size()-1,find,numbers);
//         if(val != -1)
//         {
//             ans[0] = i+1;
//             ans[1] = val+1;
//             return ans;
//         }
//     }
//     ans[0] = -1;
//     ans[1] = -1;
//     return ans;
// }

// Approach 2
vector<int> twoSum(vector<int>& numbers, int target) 
{
    map<int,int> m;
    vector<int> ans(2);
    for(int i=0; i<numbers.size(); i++)
    {
        m[target - numbers[i]] = i+1;
    }

    for(int i=0; i<numbers.size(); i++)
    {
        if(m.find(numbers[i]) != m.end())
        {
            ans[0] = min(m[numbers[i]],i+1);
            ans[1] = max(m[numbers[i]],i+1);
            return ans;
        }
    }

    ans = {-1,-1};
    return ans;
}

// Approach 3 - TC = O(n) and SC = O(1)
vector<int> twoSum(vector<int>& numbers, int target) 
{
    vector<int> ans(2);
    int i = 0;
    int j = numbers.size() - 1;
    while(i < j)
    {
        if(numbers[i] + numbers[j] == target)
        {
            ans[0] = i+1;
            ans[1] = j+1;
            return ans;
        }
        else if(numbers[i] + numbers[j] > target)
            j--;
        else
            i++;
    }
    ans = {-1,-1};
    return ans;
}