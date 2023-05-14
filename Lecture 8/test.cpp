#include <iostream>
using namespace std;

int main()
{
    int amount;
    cout<<"Enter amount: "<<endl;
    int Rs100,Rs50,Rs20,Rs1;
    cin>>amount;
    
    switch (1)
    {
    case 1: Rs100 = amount / 100;
            amount = amount % 100;
            cout << "Total no. of notes of 100 : " << Rs100 << endl;

    case 2: Rs50 = amount / 50;
            amount = amount - Rs50 * 50;
            cout << "Total no. of notes of 50 : " << Rs50 << endl;

    case 3: Rs20 = amount / 20;
            amount = amount - Rs20 * 20;
            cout<<"Total no. of notes of 20 : " << Rs20 << endl;

    case 4: Rs1 = amount / 1;
            amount = amount - Rs1 * 1;
            cout << " Total no. of notes of 1 : " << Rs1 << endl;
    }
    return 0;
}