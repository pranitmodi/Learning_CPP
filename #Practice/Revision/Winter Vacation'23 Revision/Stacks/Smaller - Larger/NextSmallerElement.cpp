#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        stack<int> st;
        st.push(-1);
        
        vector<int> ans(arr.size());
        
        for(int i=arr.size()-1; i>=0; i--)
        {
            while(st.top() >= arr[i])
                st.pop();
                    
            ans[i] = st.top();
            st.push(arr[i]);
        }
        
        return ans;
    } 
};