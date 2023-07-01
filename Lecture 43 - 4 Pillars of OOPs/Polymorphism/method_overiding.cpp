#include <bits/stdc++.h>
using namespace std;
class A
{
    public:
        void damm()
        {
            cout << "We in the parent class, hahah" << endl;
        }
};
class B:public A
{
    public:
        void damm()
        {
            cout << "Me just a child :(" << endl;
        }
};
int main()
{
    A f1;
    B f2;

    f1.damm();
    f2.damm();
    return 0;
}