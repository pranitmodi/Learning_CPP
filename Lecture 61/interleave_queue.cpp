#include <bits/stdc++.h>
using namespace std;
void interleaveQueue(queue<int> &q, int n)
{
    stack<int> s;
    for(int i=1; i<=(n/2); i++)
    {
        s.push(q.front());
        q.pop();
    }

    // adding first half in reverse order in the back
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // adding current first half in the back to bring it back to originally second half
    for(int i=1; i<=(n/2); i++)
    {
        q.push(q.front());
        q.pop();
    }

    // again sending the reverse first half to stack
    for(int i=1; i<=(n/2); i++)
    {
        s.push(q.front());
        q.pop();
    }

    // now from stack, elements will come out in order
    while(!s.empty())
    {
        q.push(s.top());
        q.push(q.front());
        q.pop();
        s.pop();
    }
}
int main()
{
    queue<int> q;
    cout << "Enter number of elments: ";
    int n;
    cin >> n;

    cout << "Enter elements: " << endl;
    for(int i=1; i<=n; i++)
    {
        int ele;
        cin >> ele;
        q.push(ele);
    }

    interleaveQueue(q,n);

    cout << "ANS: ";
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}