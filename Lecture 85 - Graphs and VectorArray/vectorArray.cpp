#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 6;

    // Vector Array - when number of vectors defined but each vector may have different lengths internally
    vector<int> arr[n];
    // Alternative
    vector<vector<int>> vect(n,vector<int>()); // also same thing

    for(int i=0; i<6; i++)
    {
        int m = 1;
        while(m)
        {
            cout << "Enter element for " << i << "th vector: ";
            int w;
            cin >> w;
            arr[i].push_back(w);

            cout << "Continue? : ";
            cin >> m; 
        }
    }

    cout << "Printing: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << i << "th: ";
        for(int j=0; j<arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}