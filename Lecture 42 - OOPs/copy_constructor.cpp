#include <bits/stdc++.h>
using namespace std;
class Hero
{
    private:
        int health;
        int level;
        char *name;
        
    public:
        Hero()
        {
            name = new char[100];
        }
        Hero(Hero& temp)
        {
            // Deep Copy
            char *ch = new char[strlen(temp.name) + 1];
            ch = temp.name;
            this->name = ch;

            this->health = temp.health;
            this->level = temp.level;
        }

        void print()
        {
            cout << "Name: " << this->name << endl;
        }
        void address()
        {
            cout << "Address: " << &name << endl;
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
        void setName(char name[])
        {
            strcpy(this->name,name); //copying char array
        }
};
int main()
{
    Hero h1;
    h1.sethealth(46);
    char okay[] = "pkauyrids";
    h1.setName(okay);
    h1.print();
    h1.address();
    cout << endl;

    Hero h2(h1);
    cout << h1.gethealth() << endl;
    h2.print();
    h2.address();
    cout << endl;
    
    char name[] = "Pranit.";
    h1.setName(name);
    h1.address();
    h1.print();

    return 0;
}