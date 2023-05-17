#include <iostream>
using namespace std;
bool isEven(int n)
{   
    if(n&1 == 1) //any numbert & 1 = 1 then that number is an odd number 
    {
        return false;
    }
    return true;
}
int main()
{
    cout << "Enter a number: " << endl;
    int n;
    cin >> n;

    cout << "Is EVEN: " << isEven(n) << endl;
    return 0;
}