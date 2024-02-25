// 3
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> arr(256,-1);
        int ans = 0;
        int cnt = 0;

        for(int i=0; i<s.length(); i++)
        {
            char ch = s[i];
            if(arr[ch] == -1)
            {
                cnt++;
                arr[ch] = i;
            }
            else
            {
                ans = max(ans,cnt);
                int w = i-arr[ch];
                cnt = min(cnt+1,w);
                arr[ch] = i;
            }
        }    
        ans = max(ans,cnt);
        return ans;
    }
};