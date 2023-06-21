#include <bits/stdc++.h>
using namespace std;
void sayDigits(int n)
{
    if(n<=0)
    {
        cout << "Answer: ";
        return;
    }

    sayDigits(n/10);

    // this being after recursive call, so that printing happens in correct format
    int d = n%10;
    
    if(d == 1)
        cout << "One" << " ";
    else if(d == 2)
        cout << "Two" << " "; 
    else if(d == 3)
        cout << "Three" << " "; 
    else if(d == 4)
        cout << "Four" << " "; 
    else if(d == 5)
        cout << "Five" << " "; 
    else if(d == 6)
        cout << "Six" << " "; 
    else if(d == 7)
        cout << "Seven" << " "; 
    else if(d == 8)
        cout << "Eight" << " "; 
    else if(d == 9)
        cout << "Nine" << " ";
    else if(d == 0)
        cout << "Zero" << " ";

}
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    sayDigits(n);

    return 0;
}