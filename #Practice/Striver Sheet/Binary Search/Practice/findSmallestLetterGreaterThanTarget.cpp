// 744
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int n = letters.size();
        if(((int)target >= (int)letters[n-1]) || ((int)target < (int)letters[0]))
            return letters[0];

        sort(letters.begin(),letters.end());
        int s = 0;
        int e = n-1;
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(letters[mid] == target && mid<n-1)
            {
                while(letters[mid] == target)
                    mid++;
                return letters[mid];
            }
            else if((int)letters[mid] > (int)target)
                e = mid-1;
            else
                s = mid+1;
        }    

        return letters[s];
    }
};