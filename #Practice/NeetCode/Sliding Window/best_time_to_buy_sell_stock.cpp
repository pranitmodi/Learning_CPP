// leetCode - 121
#include <bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
        int maxProfit(vector<int>& prices)
        {
            int maxi = prices[0];
            int mini = prices[0];
            int ind_mini = 0;
            int ind_maxi = 0;
            int ans = 0;

            for(int i=0; i<prices.size(); i++)
            {
                if(prices[i] < mini)
                {
                    mini = prices[i];
                    ind_mini = i;
                }

                if(prices[i] > maxi || (ind_maxi <= ind_mini && prices[i] > mini))
                {
                    maxi = prices[i];
                    ind_maxi = i;
                }

                if(ind_maxi > ind_mini && (maxi-mini) > ans)
                {
                    ans = maxi - mini;
                }
            }

            return ans;
        }
};