#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5];
    cout << "Enter numbers: " << endl;
    for(int i=0; i<5; i++) 
    {
        cin >> arr[i];
    }

    cout << "Enter the element to be founded: ";
    int w;
    cin >> w;

    for(int i=0; i<5; i++) 
    {
        if(w == arr[i])
        {
            cout << "Found!" << endl;
            return 0;
        }
    }

    cout << "not found!" << endl;
    return 0;
}