#include <bits/stdc++.h>
using namespace std;
void Combination(string str, int i, string mapping[], vector<char> output, vector<vector<char>> &ans)
{
    if(i >= str.length())
    {
        ans.push_back(output);
        return;
    }

    int c = str[i++] - '0';
    string s = mapping[c];

    for(int j=0; j<s.length(); j++)
    {
        output.push_back(s[j]);
        Combination(str,i,mapping,output,ans);

        // because we are in a for loop and for next character we want the output that was during the start of the function 
        output.pop_back();
    }
}
int main()
{
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string str = "234";
    vector<vector<char>> ans;
    vector<char> output;
    Combination(str,0,mapping,output,ans);

    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}