#include <bits/stdc++.h>
using namespace std;
class A
{
    public: 
        int a;
        int b;

        int add()
        {
            return a+b;
        }

        void operator+ (A &obj)
        {
            int v1 = this->a;
            int v2 = obj.a;

            cout << "Output: " << v1+v2 << endl;
        }

        void operator+ (int w)
        {
            int v1 = this->a;
            int v2 = w;

            cout << "Output: " << v1+v2 << endl;
        }

        void operator() ()
        {
            cout << "Hello, bracket!  " << this->a << endl;
        }
};
int main()
{
    A a1;
    a1.a = 345;

    A a2;
    a2.a = 5;

    a2+a1; //object + object
    a1 + 45; //object + int

    // no second part
    a1(); // Hello, bracket!  345
    a2(); // Hello, bracket!  5

    return 0;
}