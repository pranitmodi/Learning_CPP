#include <iostream>
using namespace std;
int main()
{
    int i;
    for(i=1; i<=10; i++)
    {
        cout << i <<endl;
        if(i==4)
            break;
    }
    cout << "New: " << endl;
    for(i=1; i<=10; i++)
    {
        cout << i <<endl;
        if(i==7)
            // break;
            exit(0);
    }
    cout<<"Last: " << endl;
    for(i=1; i<=10; i++)
    {
        cout << i <<endl;
    }
    return 0;
}