#include <bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool check(int A[], int N, int mid, int M)
    {
        int c = 1;
        int i = 0;
        int sum = 0;
        while(i<N)
        {
         
            if(sum + A[i] <= mid)
                sum += A[i];
            else
            {
                c++;
                if(c>M || A[i] > mid)
                    return false;
                sum = A[i];
            }
                
            i++;
        }
        
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        int s = 0;
        int sum = 0;
        for(int i=0; i<N; i++)
            sum += A[i];
            
        int ans = -1;
        int e = sum;
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            
            if(check(A,N,mid,M))
            {
                ans = mid;
                e = mid-1;
            }
            else
                s = mid+1;
        }
        
        return ans;
    }
};