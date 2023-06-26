#include <bits/stdc++.h>
using namespace std;
class Hero
{
    private:
        int health;
        int level;
        char w;
    public:
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
    cout << "Size of the object: " << sizeof(h1) << endl; //12, instead of 4+4+2=10, beacuse PADDING and Greedy alignment is involved.

    cout << "Enter health: ";
    int h;
    cin >> h;

    cout << "Enter level: ";
    int l;
    cin >> l;

    h1.sethealth(h);
    cout << "Health: " << h1.gethealth() << endl;

    cout << "Size of the object: " << sizeof(h1) << endl; 
    return 0;
}