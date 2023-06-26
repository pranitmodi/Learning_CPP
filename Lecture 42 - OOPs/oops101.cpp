#include <bits/stdc++.h>
using namespace std;

#include "random.cpp" // to use classes from other programs

class Hero
{
    public:
        int health;
        char level;
};
int main()
{
    Hero h1;
    cout << "Enter Health: " << endl;
    cin >> h1.health; //this will show error if health has not been made public, by deafult it will be private

    cout << "Health is: " << h1.health << endl;
    cout << "Level is: " << h1.level << endl; 

    okay ok; //using class function from other program
    ok.print();

    return 0;
}