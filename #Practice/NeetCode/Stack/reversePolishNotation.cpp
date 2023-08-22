// LeetCode - 150
#include <bits/stdc++.h>
using namespace std;
int evalRPN(vector<string>& tokens) 
{
    stack<int> s;
    for(int i=0; i<tokens.size(); i++)
    {
        if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            char ch = tokens[i][0];
            int res;
            switch(ch)
            {
                case '+': 
                    res = a+b;
                    break;

                case '-': 
                    res = b-a;
                    break;

                case '*': 
                    res = a*b;
                    break;

                case '/': 
                    res = b/a;
                    break;
            }
            s.push(res);
        }
        else
        {
            s.push(stoi(tokens[i]));
        }
    }    
    return s.top();
}