#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[20];
    cout << "Enter number of elements: ";
    int n;
    cin >> n;

    cout << "Enter elements: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    stack<int> st;
    vector<int> v;
    st.push(-1);

    for(int i=n-1; i>=0; i--)
    {
        if(st.top() < arr[i])
        {
            v.push_back(st.top());
        }
        else
        {
            while(st.top() >= arr[i])
            {
                st.pop();
            }
            v.push_back(st.top());
        }
        st.push(arr[i]);
    }

    reverse(v.begin(), v.end());
    for(int i:v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}