// 946
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int> st;
        int i=0;
        for(int j=0; j<popped.size(); j++)
        {
            if(st.empty())
                st.push(pushed[i++]);

            while(st.top() != popped[j] && i<pushed.size())
            {
                st.push(pushed[i++]);
            }

            if(i == pushed.size() && !st.empty() && st.top() != popped[j])
            {
                return false;
            }

            while(!st.empty() && st.top()==popped[j])
            {
                st.pop();
                j++;
                if(j == popped.size())
                    return true;
            }
            j--;
        }
        return true;
    }
};