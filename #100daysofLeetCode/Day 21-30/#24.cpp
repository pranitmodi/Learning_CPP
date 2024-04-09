// 412. Fizz Buzz
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> ans;
        for(int t=1; t<=n; t++)
        {
            if(t%3==0 && t%5==0)
                ans.push_back("FizzBuzz");
            else if(t%3==0)
                ans.push_back("Fizz");
            else if(t%5==0)
                ans.push_back("Buzz");
            else
                ans.push_back(to_string(t));
        }

        return ans;
    }
};