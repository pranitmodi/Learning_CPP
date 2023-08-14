// leetCode - 3
#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    queue<int> q;
    map<int,bool> check;
    int ans = 0;
    int count = 0;
    for(int i=0; i<s.length(); i++)
    {
        int ch = (int) s[i];
        if(check.find(ch) == check.end())
        {
            check[ch] = true;
            q.push(ch);
            count++;
        }
        else
        {
            if(count > ans)
                ans = count;

            while(q.front() != ch && !q.empty())
            {
                check.erase(q.front());
                q.pop();
                count--;
            }
            q.pop();
            count--;

            check[ch] = true;
            q.push(ch);
            count++;
        }
    }
    if(count > ans)
        return count;
    return ans;
}
int main()
{
    string str = "abcabcbb";
    // cout << "Enter String: " << endl;
    // cin >> str;

    cout << "Ans: " << lengthOfLongestSubstring(str) << endl;
}
