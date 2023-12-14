// 605
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int front = -1;
        int back = 0;

        int c = 0;
        for(int i=0; i<flowerbed.size()-1; i++)
        {
            front = flowerbed[i+1];
            if((flowerbed[i] == 0) && !front && !back)
            {
                c++;
                flowerbed[i] = 1;
            }
            
            back = flowerbed[i];
        }    
        
        if((flowerbed[flowerbed.size()-1] == 0) && !back)
            c++;

        if(c >= n)  
            return true;
        
        return false;

    }
};