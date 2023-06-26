#include <bits/stdc++.h>
using namespace std;
class Hero
{
    private:
        int health;
        int level;
        char w;
        
    public:
        // Constructor
        Hero() //has to be under public
        {
            cout << "Constructor Called" << endl;
        }

        Hero(int health)
        {
            cout << "Value of this: " << this << endl;
            this->health = health;
        }

        int gethealth()
        {
            return health;
        }
        int getlevel()
        {
            return level;
        }
        int sethealth(int h)
        {
            health = h;
        }
        int setlevel(int l)
        {
            level = l;
        }
};
int main()
{
    // static alloted
    Hero h1;

    // dynamically allocation
    Hero *h = new Hero(453);
    cout << "Address of &h: " << &(*h) << endl << endl;

    cout << "Enter health: ";
    int hea;
    cin >> hea;
    h1.sethealth(hea);
    cout << "Static Health: " << h1.gethealth() << endl;

    cout << "Dynamic Health: " << (*h).gethealth() << endl;
    h->sethealth(hea+3); //first way
    cout << "Dynamic Health: " << (*h).gethealth() << endl; // another way
    
    return 0;
}