#include <bits/stdc++.h>
using namespace std;
class Hero
{
    public:
        Hero()
        {
            cout << "Costructor called" << endl;
        }

        ~Hero()
        {
            cout << "Destructor called: " << endl;
        }
};
int main()
{
    // static
    Hero h1;

    // dynamic
    Hero *h2 = new Hero();
    delete h2; // manually called

    return 0;
}