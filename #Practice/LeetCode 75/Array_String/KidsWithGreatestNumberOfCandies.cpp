// 1431
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        int m = 0;
        for(int i=0; i<candies.size(); i++)
        {
            if(candies[i] > m)
                m = candies[i];
        }

        vector<bool> b;
        for(int i=0; i<candies.size(); i++)
        {
            if((candies[i]+extraCandies) >= m)
                b.push_back(true);
            else
                b.push_back(false);
        }

        return b;
    }
};