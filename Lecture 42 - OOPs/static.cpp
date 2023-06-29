#include <bits/stdc++.h>
using namespace std;
class Hero
{
    public:
        int health;
        static int timeToComplete; //declaration
        void print()
        {
            cout << "Health: " << health;
            cout << endl << "Time: " << Hero::timeToComplete << endl;
        }
        static void random()
        {
            Hero::timeToComplete = 8945;
        }
};
int Hero::timeToComplete = 67; //initialization
int main()
{
    Hero h1;
    h1.health = 344566;
    h1.print();
    cout << endl;

    Hero::random();

    h1.print();
    cout << endl;

    cout << "Individual: " << Hero::timeToComplete << endl; //access like this

    return 0;
}