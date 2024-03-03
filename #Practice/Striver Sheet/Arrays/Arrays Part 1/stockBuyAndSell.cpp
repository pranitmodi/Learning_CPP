// 121
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int result = 0;
        int mini = prices[0];

        for(int i=1; i<prices.size(); i++)
        {
            result = max(prices[i] - mini, result);
            mini = min(mini,prices[i]);
        }    

        return result;
    }
};