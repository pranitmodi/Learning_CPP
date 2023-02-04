#include <iostream>
using namespace std;
int main()
{
    /*
        A
        BB
        CCC
        DDDD
    */
    int n;
    cout << "Enter the number of reows needed: " << endl;
    cin >> n;

    cout << "The desired pattern is: " << endl;

    int i = 1;
    int j;
    char ch;
    while (i <= n)
    {
        ch = (char) i + 64;
        j = 1;
        while(j <= i)
        {
            cout << ch;
            j++;
        }
        cout << endl;
        i++;
    }
}