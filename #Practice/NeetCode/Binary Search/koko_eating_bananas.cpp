#include <bits/stdc++.h>
using namespace std;
int check(vector<int>& piles, int mid)
{
    int h = 0;


    for(auto i:piles)
    {
        if(i < mid)
            h++;
        else if(i%mid == 0)
            h = h + (i/mid);
        else 
            h = h + (i/mid) + 1;
    }
    return h;
}
int minEatingSpeed(vector<int>& piles, int h) 
{
    if(piles.size() == 1)
    {
        return check(piles,h);
    }

    int maxi = piles[0];
    for(auto i:piles)
    {
        if(i > maxi)
            maxi = i;
    }

    cout << maxi << endl;
    int s = 0;
    int e = maxi;
    int ans = maxi;

    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(mid == 0)
            break;
        int c = check(piles,mid);
        if(c > h)
        {
            s = mid + 1; 
        }
        else
        {
            if(c <= h && mid < ans)
            {
                ans = mid;
            }
            e = mid - 1;
        }
    }
    if(ans == maxi)
        return s;
    return ans;
}