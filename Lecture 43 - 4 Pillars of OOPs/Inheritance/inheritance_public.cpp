#include <bits/stdc++.h>
using namespace std;
class Human
{
    public:
        int height;
        int age;
        int weight;

        int getAge()
        {
            return this->age;
        }
        void setWeight(int w)
        {
            this->weight = w;
        }
};
class Male:public Human
{
    public: 
        string odor;

        void sleep()
        {
            cout << "Male is sleeping" << endl;
        }
};
int main()
{
    Male m1;
    cout << "Age: " << m1.age << endl;
    m1.age = 98;
    cout << "Age: " << m1.age << endl;
    m1.sleep();

    cout << "Odor: " << m1.odor << endl;

    return 0;
}