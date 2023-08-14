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
int main()
{
    string str = "BAAAB";

    cout << "Ans: " << characterReplacement(str,2) << endl;
}