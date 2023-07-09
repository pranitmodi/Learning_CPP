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
            while(st.top() > arr[i])
            {
                st.pop();
            }
            v.push_back(st.top());
        }
        st.push(arr[i]);
    }

    reverse(v.begin(), v.end());