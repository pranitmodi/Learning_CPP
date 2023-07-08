#include <bits/stdc++.h> 
using namespace std;
void print(stack<char> st)
{
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
// int findMinimumCost(string str) 
// {
//     int d = str.length();
//     if(d&1)
//     return -1;
//     int open = 0;
//     int close = 0;
//     for(int i=0; i<d; i++)
//     {
//     char ch = str[i];
//     if (ch == '{')
//         open++;
//     else if (ch == '}')
//         close++;
//     }
//     cout << "open: " << open << endl;
//     cout << "close: " << close << endl;
//     if(close > open)
//     return (close-open)/2;
//     else
//     return (open-close)/2;
// }

int findMinimumCost(string str) 
{
    int open = 0;
    int close = 0;
    int d = str.length();
    if(d&1)
    return -1;

    stack<char> st;
    int count = 0;
    for (int i = 0; i < d; i++) 
    {
    char ch = str[i];
    if (st.empty() && ch == '}')
    {
        st.push(ch);
        close++;
    }
    else if(ch == '{')
    {
      st.push(ch);
      open++;
    }
    else
    {
        char ch1 = st.top();
        if(ch1 == '{')
        {
          st.pop();
          open--;
        }
        else
        {
          count++;
          st.pop();
          close--;
        }
    }
    } 
    if(open&1 == 1 && close&1 == 1)
    {
      open--;
      close--;
      count = count + 2;
    }
    count = count + (open/2) + (close/2);
    return count;
}

// Approach 2
int findMinimumCost(string str) 
{
    int open = 0;
    int close = 0;
    int d = str.length();
    if(d&1)
    return -1;

    stack<char> st;
    int count = 0;
    for (int i = 0; i < d; i++) 
    {
    char ch = str[i];
    if(ch == '{')
    {
        st.push(ch);
        open++;
    }
    else
    {
        if(!st.empty() && st.top() == '{')
        {
            st.pop();
            open--;
        }
        else
        {
            st.push(ch);
            close++;
        }
    }
    } 
    count = (open+1)/2 + (close+1)/2;
    return count;
}
int main()
{
    string str;
    cout << "Enter String: ";
    cin >> str;

    cout << "Ans: " << findMinimumCost(str) << endl;
    
    return 0;
}