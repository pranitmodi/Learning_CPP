#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cout << "Enter a and b " << endl;
    cin >> a >> b;

    cout << "Enter the operator(*,/,+,-): " << endl;
    char op;
    cin >> op;

    switch(op)
    {
        case '-': 
            cout << "a-b: " << (a-b) << endl;
            break;
        case '+': 
            cout << "a+b: " << (a+b) << endl;
            break;
        case '*': 
            cout << "a*b: " << (a*b) << endl;
            break;
        case '/': 
            cout << "a/b: " << (a/b) << endl;
            break;
        default: cout << "Invalid operator entered" << endl;
    }
    return 0;
}