// 134
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int front = 0;
        int def = 0;
        int bal = 0;
        for(int i=0; i<gas.size(); i++)
        {
            bal = bal + gas[i] - cost[i];
            if(bal < 0)
            {
                def += bal;
                front = i+1;
                bal = 0;
            }
        }

        if(def + bal >= 0)
            return front;

        return -1;
    }
};