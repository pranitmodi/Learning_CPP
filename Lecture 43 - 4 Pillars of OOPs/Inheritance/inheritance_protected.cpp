#include <bits/stdc++.h>
using namespace std;
class Human
{
    public: 
        int height;
        int age;
    
    protected:
        int weight;

        void okay()
        {
            cout << "Protected Super Class" << endl;
        }
};
class Sapien:protected Human
{
    public:
        int year;

        void display()
        {
            cout << this->weight << endl;
            okay();
        }

    protected:
        void display2()
        {
            cout << this->weight << endl;
            okay();
        }
};
int main()
{
    Sapien s1;
    s1.display();

    // AS WE CANNOT ACCESS PROTECTED OF ANY OF THE CLASSES FROM HERE
    // cout << endl << endl;
    // s1.okay(); 
    // cout << endl << endl;
    // s1.display2();

    // Human h1;
    // h1.okay();
}