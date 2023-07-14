#include <bits/stdc++.h>
using namespace std;
string FirstNonRepeating(string A)
{
    int arr[26] = {0};
    queue<char> q;
    q.push(A[0]);
    arr[A[0]-97] = 1;

    if(A.length() == 0)
        return A;

    for(long long int i=1; i<A.length(); i++)
    {
        char ch = A[i];
        int m = ch - 97;
        if(arr[m] == 0)
        {
            q.push(ch);
            arr[m] = 1;
        }
        else if(arr[m] == 1)
            arr[m] = 2;
        if(arr[q.front()-97] == 1)
            A[i] = q.front();
        else    
        {
            while(arr[q.front()-97] == 2 && !q.empty())
                q.pop();
            
            if(q.empty())
                A[i] = '#';
            else
                A[i] = q.front();
        }
    }

    return A;
}

int main()
{
    string s;
    cout << "Enter String: ";
    cin >> s;

    cout << s.length() << endl;

    string str = FirstNonRepeating(s);

    cout << str << endl;


    return 0;
}