#include <bits/stdc++.h>
using namespace std;
class Data
{
    public:
        int val;
        int i;
        int j;

        Data(int val, int i, int j)
        {
            this->val = val;
            this->i = i;
            this->j = j;
        }
};
class compare
{
    public:
        bool operator() (Data *a, Data *b)
        {
            return a->val > b->val;
        }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<Data*,vector<Data*>,compare> mini;

    for(int i=0; i<k; i++)
    {
        Data *d = new Data(kArrays[i][0],i,0);
        mini.push(d);
    }

    vector<int> ans;

    while(mini.size() > 0)
    {
        Data *a = mini.top();
        ans.push_back(a->val);
        mini.pop();

        if(a->j+1<kArrays[a->i].size())
        {
            Data *d1 = new Data(kArrays[a->i][(a->j)+1],a->i,(a->j)+1);
            mini.push(d1);
        }
    }

    return ans;
}
