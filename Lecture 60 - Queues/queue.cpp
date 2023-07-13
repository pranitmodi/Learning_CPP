#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Creating a queue
    queue <int>q;

    cout << q.size() << endl;

    q.push(21);
    q.push(34);

    cout << q.size() << endl;
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;

    if(q.empty())
        cout << "Empty!" << endl;
    else
        cout << "Not Empty" << endl;


    return 0;
}