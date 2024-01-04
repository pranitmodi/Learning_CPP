// 1441
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        vector<string> ans;
        int i = 1;
        int j = 0;
        while(j<target.size())
        {
            while(target[j] != i)
            {
                ans.push_back("Push");
                ans.push_back("Pop");
                i++;
            }
            j++;
            ans.push_back("Push");
            i++;
        }

        return ans;
    }
};