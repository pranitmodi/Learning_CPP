#include <iostream>
using namespace std;
int main()
{
    for(int i = 1; i<=5 ; i++)
    {
        cout << "Hey" << endl;
        cout << "Hello" << endl;
        continue;

        cout << "Kerde reply bhai?" << endl; //This is not printed
    }
}