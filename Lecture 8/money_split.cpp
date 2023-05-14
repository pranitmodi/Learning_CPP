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

// #include <iostream>
// using namespace std;

// int main()
// {
//     int amount;
//     cout<<"Enter amount: "<<endl;
//     int Rs100,Rs50,Rs20,Rs1;
//     cin>>amount;
    
//     switch (1)
//     {
//     case 1: Rs100 = amount / 100;
//             amount = amount % 100;
//             cout << "Total no. of notes of 100 : " << Rs100 << endl;

//     case 2: Rs50 = amount / 50;
//             amount = amount - Rs50 * 50;
//             cout << "Total no. of notes of 50 : " << Rs50 << endl;

//     case 3: Rs20 = amount / 20;
//             amount = amount - Rs20 * 20;
//             cout<<"Total no. of notes of 20 : " << Rs20 << endl;

//     case 4: Rs1 = amount / 1;
//             amount = amount - Rs1 * 1;
//             cout << " Total no. of notes of 1 : " << Rs1 << endl;
//     }
//     return 0;
// }