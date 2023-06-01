// Number of subsets with product less than k
// GfG
// Given an array arr[] of N elements. Find the number of non-empty subsets whose product of elements is less than or equal to a given integer K.
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int numOfSubsets(int arr[], int N, int K) 
    {
        int ans = 0;
        int p;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                p = arr[j];
                int c = 0;
                int k = j+1;
                while(c<i)
                {
                    if(k>N-1)
                        break;
                    p = p * arr[k];
                    k++;
                    c++;
                }
                if(p <= K)
                {
                    ans++;
                    cout << i << " " << j << endl;
                }
            }
        }
        return ans;
    }
    
};