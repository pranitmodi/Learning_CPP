#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5,6,5,4,3,2,1};
    
    // a^a = 0
    // a^0 = a

    int s = 0;
    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++)
    {
        s = s^arr[i];
    }

    cout << "Unique Element: " << s << endl;
}