#include <bits/stdc++.h>
using namespace std;
vector<int> smallRight(vector<int> arr)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(arr.size());    

    for(int i=arr.size()-1; i>=0; i--)
    {
        while(st.top() != -1 &&  arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> smallLeft(vector<int> arr)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(arr.size());    

    for(int i=0; i<arr.size(); i++)
    {
        while(st.top() != -1 && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
int main()
{
    vector<int> heights;
    cout << "Enter number of elements: ";
    int n;
    cin >> n;

    cout << "Enter elements: " << endl;
    for(int i=0; i<n; i++)
    {
        int ele;
        cin >> ele;
        heights.push_back(ele);
    }

    vector<int> left = smallLeft(heights);
    vector<int> right = smallRight(heights);
    int ans = 0;
    for(int i=0; i<heights.size(); i++)
    {
        int l = heights[i];
        if(right[i] == -1)
            right[i] = heights.size();
        int b = right[i] - left[i] - 1;

        cout << "oka3" << endl;
        int area = l * b;
        ans = max(ans, area);
    }

    cout << "Ans: " << ans << endl;
    //return ans;
    return 0;
}