#include <bits/stdc++.h>
using namespace std;

// copied code
string minWindow(string s, string t) 
{
    int m = s.size();
    int n = t.size();
    if (n > m) 
        return "";  // Handle the case where t is longer than s

    int map[256] = {0};  // Create an array to store the frequency of characters in string t
    for (char c : t) 
    {
        map[c]++;
    }

    int count = 0;  // Count of distinct characters in the current window

    int window[256] = {0};  // Create an array to track the frequency of characters in the current window
    int i = 0, start = -1, end = -1, ans = INT_MAX;  // Initialize pointers and variables

    for (int j = 0; j < m; j++) 
    {
        window[s[j]]++;  // Expand the window by adding character at index j
        if (window[s[j]] <= map[s[j]])
        {
            count++;  // Increment count if the character is present in t
        }

        if (count == n) 
        {  // If all characters of t are present in the window
            while (map[s[i]] == 0 || window[s[i]] > map[s[i]])
            {
                // Contract the window from the left side
                // Until the element dowa not exist in t string
                // or exists more time in current window than in t string
                window[s[i]]--;
                i++; 
            }
            
            if ((j - i + 1) < ans)
            {
                ans = j - i + 1;
                start = i;
                end = j;  // Update the minimum window indices
            }

            // shifting window
            window[s[i]]--;
            i++;
            count--;
        }
    }

    if (start == -1) 
        return "";  // No valid window 
        
    string final = "";
    for (int x = start; x <= end; x++) 
    {
        final += s[x];  // Extract the minimum window substring
    }

    return final;
}

// NOT COMPLETEDDD
string minWindow(string s, string t)
{
    int c1[26] = {0};
    int c2[26] = {0};
    for(int i=0; i<t.length(); i++)
    {
        int c = t[i] - 'A';
        c1[c]++;
    }
    for(int i=0; i<s.length(); i++)
    {
        int c = s[i] - 'A';
        c2[c]++;
    }
    int i = 0;
    int j = s.length();
    while(i<j)
    {
        int c = s[i] - 'A';
        int w = s[j] - 'A';
        if(c2[c] - c1[c] > 0)
        {
            i++;
            c2[c]--;
        }
        else if(c2[w] - c1[w] > 0)
        {
            j--;
            c2[w]--;
        }

        int p = 0;
        for(int k=0; k<26; k++)
        {
            if(c1[k]!=c2[k])
                break;
            p = 1;
        }
        if(p == 1)
        {
            break;
        }
    }
    string str = "";
    for(int m=i; m<=j; m++)
    {
        str = str + s[m];
    }
    return str;
}
int main()
{
    cout << minWindow("ADOBECODEBANC","ABC") << endl;
}