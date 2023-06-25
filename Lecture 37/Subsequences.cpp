#include<bits/stdc++.h>
using namespace std;
void SubSequence(string str, string output, int i, vector <string>& ans)
{
    if(i>=str.length())
    {
        if(output.length() > 0)
            ans.push_back(output);
        return;
    }

    char ele = str[i++];

    //exclude 
    SubSequence(str,output,i,ans);

    output.push_back(ele);
    SubSequence(str,output,i,ans);
}
int main()
{
    string str;
    cout << "Enter String: ";
    cin >> str;

    cout << "String: " << str << endl;

    vector <string> ans;
    string output = "";
    int i = 0;

    SubSequence(str, output, i, ans);

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