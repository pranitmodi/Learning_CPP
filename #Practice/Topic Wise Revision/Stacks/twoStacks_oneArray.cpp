#include <bits/stdc++.h>
using namespace std;
class Twostack
{
    public:
        int size;
        int top1;
        int top2;
        int *arr;

    Twostack(int s)
    {
        this->size = s;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int val)
    {
        if(top2-top1 > 1)
        {
            top1++;
            arr[top1] = val;
            cout << "Pushed " << val << endl;
        }
        else
            cout << "Stack Overflow" << endl;
    }

    void push2(int val)
    {
        if(top2-top1 > 1)
        {
            top2--;
            arr[top2] = val;
            cout << "Pushed " << val << endl;
        }
        else    
            cout << "Stack Overflow" << endl;
    }

    int pop1()
    {
        if(top1 == -1)
            return -1;
        else
            return arr[top1--];
    }

    int pop2()
    {
        if(top2 == size)
            return -1;
        else    
            return arr[top2++];
    }
};
int main()
{
    Twostack st(6);
    st.push1(1);
    st.push1(2);
    st.push2(4);
    st.push1(3);
    st.push1(56);
    st.push1(2);
    cout << st.pop1() << endl;
    st.push1(2);
    cout << st.pop2() << endl;
    st.push1(2);
}