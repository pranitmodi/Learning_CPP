// LeetCode - 49
#include <bits/stdc++.h>
using namespace std;

// Approach 1 - TLE : TC - O(n^2)
vector<vector<string>> groupAnagrams1(vector<string>& strs) 
{
    vector<vector<int>> check;
    for(int i=0; i<strs.size(); i++)
    {
        vector<int> temp(26,0);
        for(int j=0; j<strs[i].length(); j++)
        {
            char ch = strs[i][j];
            temp[ch-97]++;
        }
        check.push_back(temp);
    }

    // for(auto i:check)
    // {
    //     for(auto j:i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    map<int,bool> m;
    vector<vector<string>> ans;
    for(int i=0; i<strs.size(); i++)
    {
        vector<string> temp;
        if(m[i] != true)
        {
            temp.push_back(strs[i]);
            m[i] = true;
            vector<int> v1 = check[i];
            for(int j=i+1; j<strs.size(); j++)
            {
                vector<int> v2 = check[j];
                if(v1 == v2 && m[j] != true)
                {
                    temp.push_back(strs[j]);
                    m[j] = true;
                }
            }
            ans.push_back(temp);
        }
    }
    return ans;
}

// Approach 2 - Accepted
// Sorting the enter strings
vector<vector<string>> groupAnagrams2(vector<string>& strs) 
{
    map<string,vector<string>> m;
    for(auto s:strs)
    {
        string str = s;
        sort(str.begin(),str.end());
        m[str].push_back(s);
    }

    vector<vector<string>> ans;
    for(auto i:m)
    {
        ans.push_back(i.second);
    }
    return ans;
}
int main()
{
    vector<string> s = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> w = groupAnagrams2(s);

    for(auto i:w)
    {
        for(auto j:i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}