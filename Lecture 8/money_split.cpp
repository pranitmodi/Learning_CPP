#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the amount: " << endl;
    cin >> n;

    int fifty = 0;
    int hundred = 0;
    int twenty = 0;
    int one = 0;

    cout << "Currency BreakUp: " << endl;

    if(n > 100)
    {
        hundred = n/100;
        n = n % 100;
    }
    if(n > 50)
    {
        fifty = n/50;
        n = n % 50;
    }
    if(n > 20)
    {
        twenty = n/20;
        n = n % 20;
    }
    if(n > 1)
    {
        one = n;
    }

    cout << "100 Notes: " << hundred << endl;
    cout << "50 Notes: " << fifty << endl;
    cout << "20 Notes: " << twenty << endl;
    cout << "1 Notes: " << one << endl;
    return 0;
}