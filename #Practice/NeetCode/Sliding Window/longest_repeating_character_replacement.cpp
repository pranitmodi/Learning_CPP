// leetCode - 3
#include <bits/stdc++.h>
using namespace std;

// TC - O(n^2)
int characterReplacement(string s, int k)
{
    int ans = 0;
    for(int i=0; i<s.length(); i++)
    {
        char ch = s[i];
        int c = k;
        int j = i;
        cout << ch << endl;
        while((c>0 || s[j] == ch) && j<s.length())
        {
            cout << s[j] << " ";
            if(s[j] != ch)
                c--;
            j++;
        }
        cout << "C: " << c << endl;
        if(c > 0)
        {
            if((j-i + c) > ans)
                ans = j - i + c;
        }
        if((j-i) > ans)
            ans = j - i;
    }
    if(ans > s.length())
        return s.length();
    return ans;
}

// TC - O(n)
int characterReplacement1(string s, int k) 
{
    int n = s.size();
    int i = 0, j = 0, maxi = 0;
    unordered_map<char,int>mp;
    int ans = -1;
    while(j < n)
    {
        mp[s[j]]++;
        // maxi - the count of the element that i smaximum in the current window
        maxi = max(maxi, mp[s[j]]);

        // means all other elemnts other than the most frequent one, if they are more thant the limit k, increment the window
        if((j-i+1) - maxi > k)
        {
            mp[s[i]]--;
            i++;
        }
        ans = max(ans, (j-i+1));
        j++;   
    }
    return ans;
}


int main()
{
    string str = "BAAAB";

    cout << "Ans: " << characterReplacement(str,2) << endl;
}