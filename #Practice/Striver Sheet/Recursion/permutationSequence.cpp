// 60
#include <bits/stdc++.h>
using namespace std;

// my solution - did it on my own - 100% better
class Solution {
public:
    void solve(string &ans,int i, int n, int &k, vector<int> &fact, vector<int> &v)
    {
        // base case
        if(i == n)
            return;

        int w = 1;
        while(k - fact[n-i] > 0)
        {
            k = k - fact[n-i];
            w++;
        }

        int t = 0;
        while(w>0)
        {
            if(v[t] == 1)
                w--;
            t++;
        }
        v[t-1] = 0;
        ans += to_string(t);

        solve(ans,i+1,n,k,fact,v);
    }
    string getPermutation(int n, int k) 
    {
        int s = 1;
        vector<int> v(n,1);
        vector<int> fact(11);
        for(int i=1; i<=9; i++)
        {
            s = s * i;
            fact[i] = s;
        }    

        string ans = "";
        int i = 1;
        solve(ans,i,n,k,fact,v);

        i = 0;
        while(v[i] != 1)
            i++;
            
        ans += to_string(i+1);
        return ans;
    }
};

// TLE
class Solution {
public:
    void solve(vector<string> &ans,int n, int i, string s)
    {
        if(i == n)
        {   
            ans.push_back(s);
            return;
        }

        for(int w=i; w<n; w++)
        {
            swap(s[i],s[w]);
            solve(ans,n,i+1,s);
            swap(s[i],s[w]);
        }
    }
    string getPermutation(int n, int k) 
    {
        string s = "";
        for(int i=1; i<=n; i++)
            s = s + (to_string(i));

        vector<string> ans;
        solve(ans,n,0,s);
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};