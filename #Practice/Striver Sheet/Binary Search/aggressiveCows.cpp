#include <bits/stdc++.h>
using namespace std;
bool isPossible(int mid, vector<int> &stalls, int k)
{
    int lastPos = stalls[0];
    int count = 1;
    for(int i = 0; i<stalls.size(); i++)
    {
        if(stalls[i] - lastPos >= mid) //means condition satisfied for one cow, onto next
        {
            count++;
            if(count == k) // what if we have already alloted all the cows
                return true;
            lastPos = stalls[i]; //this becomes where the distance will be calculted for this now from now.
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int s = 0;
    int e = stalls[stalls.size()-1] - stalls[0];
    int mid;
    int ans = -1;

    while(s <= e)
    {
        mid = s + (e-s)/2;    
        if(isPossible(mid,stalls,k))
        {
            s = mid + 1; //if this is possible and we need MAXIMUM(MINIMUM distance between two) so move start to mid + 1
            ans = mid;
        }
        else
            e = mid - 1;
    }
    return ans;
}