#include <bits/stdc++.h>
using namespace std;
class Hero
{
    private:
        int health;
        int level;
        char w;
        
    public:
        Hero()
        {
            
        }
        Hero(Hero& temp)
        {
            this->health = temp.health;
            this->level = temp.level;
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
    Hero h1;
    h1.sethealth(46);

    Hero h2(h1);
    cout << h1.gethealth() << endl;

    return 0;
}