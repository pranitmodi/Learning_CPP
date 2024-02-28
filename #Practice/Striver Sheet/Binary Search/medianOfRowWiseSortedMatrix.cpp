#include <bits/stdc++.h>
using namespace std;
int median(vector<vector<int>> &matrix, int m, int n) 
{
    int row = matrix.size();
    int col = matrix[0].size();
    int s = 1;
    int e = 1;

    for(int i=0; i<row; i++)
    {
        e = max(e,matrix[i][col-1]);
    }

    while(s<=e)
    {
        int mid = s + (e-s)/2;

        int cnt = 0;
        for(int i=0; i<row; i++)
        {
            int c = 0;
            while(c<col && matrix[i][c] <= mid)
            {
                cnt++;
                c++;
            }
        }

        if(cnt <= (row*col)/2)
            s = mid + 1;
        else    
            e = mid - 1;
    }

    return s;
}