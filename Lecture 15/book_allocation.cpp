#include <bits/stdc++.h>
using namespace std;
bool isPossible(int arr[], int n, int m, int mid)
{
    int c = 1; //Student Count
    int sum = 0; //Number of pages allocated to each student
    for(int i=0; i<n; i++)
    {
        if(sum + arr[i] <= mid)
         sum = sum + arr[i];
        else
        {
            c++;
            if(c > m || arr[i] > mid)
            {
                return false;
            }
            sum = arr[i];
        }   
    }
    return true;
}
int bookAllocation(int arr[], int n, int m)
{
    int s=0;
    int e=0;
    for(int i=0; i<n; i++)
    {
        e += arr[i];
    }
    
    int ans = -1;
    int mid;
    while(s <= e)
    {
        mid = s + (e-s)/2;
        bool b = isPossible(arr,n,m,mid);
        if(b)
        {
            e = mid - 1;
            ans = mid;
        }
        else
            s = mid + 1;
    }
    return ans;
}
int main()
{
    int arr[20];
    int n,m;
    cout << "Enter the number of books: " << endl;
    cin >> n;

    cout << "Enter the pages: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the number of students: " << endl;
    cin >> m;

    int ans = bookAllocation(arr,n,m);
    cout << "The answer: " << ans << endl;

}