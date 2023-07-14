#include <bits/stdc++.h>
using namespace std;
void rev(queue<int> &q, int k)
{
    if(k == 0)
        return;
        
    int ele = q.front();
    q.pop();
    rev(q,--k);
    q.push(ele);
}
void modifyQueue(queue<int> &q, int k) 
{
    int n = q.size();
    rev(q,k);
    for(int i=1; i<=(n-k); i++)
    {
        int ele = q.front();
        q.pop();
        q.push(ele);
    }
}
int main()
{
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    modifyQueue(q,2);

    cout << "Modified: ";
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}