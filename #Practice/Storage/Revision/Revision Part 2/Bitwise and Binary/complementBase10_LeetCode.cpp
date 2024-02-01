#include <bits/stdc++.h>
using namespace std;
int bitwiseComplement(int n) 
{
    int sum = 0;
    int i = 0;
    do
    {
        if(!(n&1))
        {
            sum += (int)pow(2,i);
        }
        i++;
        n = n>>1;
    }while(n != 0);
    return sum;
}
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Answer: " << bitwiseComplement(n) << endl;
}