// 1475
#include <bits/stdc++.h>
using namespace std;
vector<int> finalPrices(vector<int>& prices) 
{
    vector<int> ans(prices.size());
    stack<int> st;
    st.push(0);

    for(int i=prices.size()-1; i>=0; i--)
    {
        while(st.top() > prices[i] && st.top()!=0)
            st.pop();

        
        ans[i] = prices[i] - st.top();
        st.push(prices[i]);
    }

    return ans;
}