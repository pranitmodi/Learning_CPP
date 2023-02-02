#include <iostream>
using namespace std;
int main()
{
    char ch;
    cout << "Enter a Character: " << endl;
    cin >> ch;
    // This also works -> ch = cin.get();

    int i = ch;
    if (i >= 65 & i<=90)
    {
        cout << "Its a upper-case character: " << ch << endl;
    }
    else if(i >= 97 & i<=122)
    {
        cout << "Its a lower-case character: " << ch << endl;
    }
    else if(i>=48 & i<=57)
    {
        cout << "Its a number: " << ch << endl;
    }
}