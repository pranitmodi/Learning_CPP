#include <bits/stdc++.h>
using namespace std;

// Approach 1
bool isValidParenthesis(string expression)
{
    int open1 = 0;
    int open2 = 0;
    int open3 = 0;
    int closed1 = 0;
    int closed2 = 0;
    int closed3 = 0;

    int l=expression.length();
    if((l==1) || (l&1 == 1))
        return false;
    for(int i=0; i<l; i++)
    {
        char ch=expression[i];
        if (ch == '{')
            open1++;
        else if (ch == '(')
            open2++;
        else if (ch == '[')
            open3++;
        else if (ch == '}')
            closed1++;
        else if(ch == ')')
            closed2++;
        else if(ch == ']')
            closed3++;
    }

    if((open1 == closed1) && (open2 == closed2) && (open3 == closed3))
        return true;
    else
        return false;
}

//Approach 2
bool check(string str)
{
    stack<char> s;
    if(str.length()&1) // if only one character is present or odd number of characters present
        return false;

    for(int i=0; i<str.length(); i++)
    {
        char ch = str[i];
        if(ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else if(s.empty()) //if the first character itself is a closing bracket
            return false;
        else
        {
            if((ch == ')' && s.top() == '(') || (ch == ']' && s.top() == '[') || (ch == '}' && s.top() == '{'))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    string str;
    cout << "Emter the String :";
    cin >> str;

    if(check(str))
        cout << "Balanced." << endl;
    else    
        cout << "Not Balanced" << endl;

    return 0;
}