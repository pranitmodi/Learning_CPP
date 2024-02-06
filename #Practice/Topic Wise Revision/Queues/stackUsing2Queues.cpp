#include<bits/stdc++.h>
using namespace std;

class QueueStack
{
    private:
        queue<int> q1;
        queue<int> q2;
    public:
        void push(int);
        int pop();
};
void QueueStack :: push(int x)
{
    q2.push(x);
    while(!q1.empty())
    {
        int d = q1.front();
        q2.push(d);
        q1.pop();
    }
    
    queue<int> q = q1;
    q1 = q2;
    q2 = q;
}
int QueueStack :: pop()
{
    int val = -1;
    if(!q1.empty())
    {
        val = q1.front();
        q1.pop();
    }
    return val;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}
