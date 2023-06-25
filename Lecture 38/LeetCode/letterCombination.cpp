// LeetCode
// 17. Letter Combinations of a Phone Number

#include <bits/stdc++.h>
using namespace std;
void Combiantion(string str, int index, string output, vector <string>& ans, string mapping[])
{
    if(index>=str.length())
    {
        ans.push_back(output);
        return;
    }

    int num = str[index] - '0';
    string s = mapping[num];
    for(int i=0; i<s.length(); i++)
    {
        output.push_back(s[i]);
        Combiantion(str,index+1,output,ans,mapping);

        //we only get ad,ae,af,be,bd----cf from the above, we also need a,b,c thus we pop
        output.pop_back();
    }
}
int main()
{
    string str;
    cout << "Enter the String: ";
    cin >> str;


    int i = 0;
    string output = "";
    vector <string> ans;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    if(str.length() <= 0)
        return 0;

    Combiantion(str,i,output,ans,mapping);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].length(); j++)
        {
            cout << ans[i][j];
        }
        cout << " ";
    }
    cout << endl;   

    return 0;
}