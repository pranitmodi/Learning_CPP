// 516. Longest Palindromic Subsequence
#include <bits/stdc++.h>
using namespace std;

// Most Optimal Solution
int longestCommonSubsequence(string text1, string text2) 
{
    if(text1 == text2)
        return text1.length();

    vector<int> curr(text2.length()+1,0);
    vector<int> next(text2.length()+1,0);

    for(int i=text1.length()-1; i>=0; i--)
    {
        for(int j=text2.length()-1; j>=0; j--)
        {
            int ans = 0;
            if(text1[i] == text2[j])
                ans = (1 + next[j+1]);
            else
            {
                int a = next[j];
                int b = curr[j+1];
                ans = max(a,b);
            }

            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}
int longestPalindromeSubseq(string s) {
    string s2 = s;
    reverse(s.begin(), s.end());
    return longestCommonSubsequence(s,s2);
}