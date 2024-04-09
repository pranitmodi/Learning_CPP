// 299. Bulls and Cows
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) 
    {
        map<char,int> m;
        for(int i=0; i<secret.length(); i++)
            m[secret[i]]++;

        int bulls = 0;
        int bears = 0;
        for(int i=0; i<guess.length(); i++)
        {
            if(guess[i] == secret[i])
            {
                bulls++;
                m[guess[i]]--;
            }
        }

        for(int i=0; i<guess.length(); i++)
        {
            if(guess[i] != secret[i] && m[guess[i]] > 0)
            {
                bears++;
                m[guess[i]]--;
            }
        }
        
        return (to_string(bulls) + "A" + to_string(bears) + "B");
    }
};