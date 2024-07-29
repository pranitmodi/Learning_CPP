// LeetCode - 443. String Compression
#include <bits/stdc++.h>
using namespace std;
int compress(vector<char>& chars) 
{
    int i = 0;
    int ans = 0;
    int n = chars.size();

    while(i < n)
    {
        int j = i+1;
        while(j<n && chars[i] == chars[j])
            j++;

        int count = j - i;
        chars[ans++] = chars[i];

        if(count > 0)
        {
            string c = to_string(count);
            for(char ch:c)
            {
                chars[ans++] = ch;
            }
        }
        i = j;
    }
    return ans;
}