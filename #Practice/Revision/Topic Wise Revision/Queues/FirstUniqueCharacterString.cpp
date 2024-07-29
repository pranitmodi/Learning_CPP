// 387
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) 
    {
        int arr[26] = {0};
        queue<int> q;
        for(int i=0; i<s.length(); i++)
        {
            arr[s[i] - 'a']++;
            if(arr[s[i] - 'a'] == 1)
                q.push(i);
        }    

        while(!q.empty())
        {
            int t = q.front();
            if(arr[s[t] - 'a'] == 1)
                return t;

            q.pop();
        }

        return -1;
    }
};