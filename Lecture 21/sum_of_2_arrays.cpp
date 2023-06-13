#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cout << "Enter number of elements (m & n): ";
    cin >> n;
    cin >> m;

    int a[20];
    int b[20];

    cout << "Enter elements of the first array: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter elements of the second array: " << endl;
    for(int i=0; i<m; i++)
    {
        cin >> b[i];
    }

    int i=n-1;
    int j=m-1;

    int e = max(m,n);
    vector<int> temp(e+1);
    temp[0] = 0;
    int c=0;

    // until last places are the same
    while(i>=0 && j>=0)
    {
        int sum = a[i] + b[j];
        if(c == 1)
        {
            sum++;
            c = 0;
        }
        if(sum > 9)
        {
            temp[e--] = sum%10;
            c = 1;
        }
        else
        {
            temp[e--] = sum;
        }
        i--;
        j--;
    }
    if(i >= 0) // if first element is bigger than second
    {
        if(c == 1) // still checking for carry
        {
            temp[e--] = a[i--] + 1;
        }
        while(i>=0)
        {
            temp[e--] = a[i--];
        }
    }
    else if(j >= 0) // if second element is bigger than first
    {
        if(c == 1)
        {
            temp[e--] = b[j--] + 1;
        }
        while(j>=0)
        {
            temp[e--] = b[j--];
        }
    }
    else if(c == 1) // for an extra counter/carry in case both array had equal number of elements
    {
        temp[e--] = 1;
    }

    // removing the empty space if the first element is still zero
    vector <int> res;
    if(temp[0] == 0)
    {
        for(int i=1; i<temp.size(); i++)
            res.push_back(temp[i]);
    }
    else 
    {
        res = temp;
    }
    

    // Printing the final answer
    cout << "Answer: ";
    for(int i:res)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}