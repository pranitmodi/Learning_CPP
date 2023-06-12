#include <iostream>
#include <array> //to sdeclare static array using stl - standard template library
using namespace std;
int main()
{
    array <int,5> a;
    cout << "Enter elements: " << endl;

    int size = a.size();

    for(int i = 0; i<size; i++)
    {
        cin >> a.at(i);
    }

    for(int i = 0; i<size; i++)
    {
        cout << a[i] << " " << endl;
    }
    cout << endl; 

    return 0;
}