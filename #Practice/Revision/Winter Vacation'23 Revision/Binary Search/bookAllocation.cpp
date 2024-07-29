#include <bits/stdc++.h>
using namespace std;
bool check(int mid, int a[], int n, int m)
{
    int c = 1;
    int sum = 0;
    int i = 0;
    while(i < n)
    {
        if(a[i] > mid)
            return false;

        if((sum+a[i]) <= mid)
        {
            sum = sum + a[i];
        }
        else
        {
            c++;
            if(c > m)
            {
                return false;
            }
            sum = a[i];
        }
        i++;
    }
    cout << "end: " << c << " " << m << endl;
    return true;

}
int findPages(int A[], int N, int M) 
{
    if(M > N)
        return -1;

    int e = 0;
    for(int i=0; i<N; i++)
    {
        e += A[i];
    }
    
    int s = 0;
    int ans = -1;
    while(s <= e)
    {
        int mid = s + (e-s)/2;
        cout << "mid: " << mid << endl;
        if(check(mid,A,N,M))
        {
            ans = mid;
            cout << "potential: " << ans << endl;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ans;
}
int main()
{
    int arr[] = {15,10,19,10,5,18,7};
    cout << findPages(arr,7,4) << endl;
}