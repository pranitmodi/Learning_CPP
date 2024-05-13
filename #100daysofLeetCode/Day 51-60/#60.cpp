// 1089. Duplicate Zeros
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) 
    {
        // int count = 0;
        // int i = 0;
        // int f = 0;
        // while(i<arr.size())
        // {
        //     if(arr[i] == 0)
        //         count++;
        //     else
        //         f++;

        //     if(i+count+1 >= arr.size())
        //         break;

        //     i++;
        // }    

        // cout << i << endl;

        // int w = arr.size()-1;
        // for(int j=i; j>=0; j--)
        // {
        //     if(arr[j] == 0)
        //     {
        //         arr[w--] = 0;
        //         if(w<0)
        //             break;
        //         arr[w--] = 0;
        //     }
        //     else
        //     {
        //         arr[w--] = arr[j];
        //         f--;
        //     }

        //     if(w<0)
        //         break;
        // }

        vector<int> s;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i] == 0)
            {
                s.push_back(0);
                s.push_back(0);
            }
            else
                s.push_back(arr[i]);
        }

        for(int i=0; i<arr.size(); i++)
        {
            arr[i] = s[i];
        }
    }
};