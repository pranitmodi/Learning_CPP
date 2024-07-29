// https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "adewfwefwghwfwe";
    vector<int> v(256,-1);

    int w = 0; // initial starting index of the substring
    int ans = 0;
    for(int i=0; i<s.length(); i++)
    {
        // Update w (starting index of current window)
        // new substring will always start with last time that element occured, what matters is the position of the last occurance, thats all
        // beacuse we make the new subtring starting point directly +1 of the last position
        w = max(w,v[s[i]]+1);
        
        ans = max(ans,(i-w+1));

        v[s[i]] = i;
    }

    cout << "Longest non-repeating string length: " << ans << endl;
}