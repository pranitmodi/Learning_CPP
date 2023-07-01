#include <bits/stdc++.h>
using namespace std;
class Human
{
    public:
        int height;

        void speak()
        {
            cout << "Human is speaking" << endl;
        }
};
class Animal
{
    public:
        int breed;

        void bark()
        {
            cout << "Animal is Barking" << endl;
        }
};

// Multiple Inheritance
class Hybrid:public Animal, public Human
{

};

int main()
{
    Hybrid h1;
    h1.bark();
    h1.speak();

    return 0;
}