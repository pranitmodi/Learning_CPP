#include <bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int> >& M, int n) 
{
    stack<int> s;
    // push all the elements in stack
    for(int i=0; i<n; i++)
    {
        s.push(i);
    }
    
    // step 2 - popping two elements and checking
    while(s.size()!=1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        
        
        if(M[a][b] == 1)
            s.push(b);
        else 
            s.push(a);
    }
    
    // single element left - checking for if its a celebrity
    int w = s.top();
    int c = 2;
    for(int i=0; i<n; i++)
    {
        if(M[w][i] != 0)
        {
            c--;
            break;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        if(i != w)
        {
            if(M[i][w] != 1)
            {
                c--;
                break;
            }
        }
    }
    
    if(c == 2)
        return w;
    else
        return -1;
    
}
