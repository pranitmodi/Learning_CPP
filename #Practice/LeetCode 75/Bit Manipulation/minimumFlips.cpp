// 1318
#include <bits/stdc++.h>
using namespace std;
int minFlips(int a, int b, int c) 
{
    int ans = 0;
    while(a!=0 || b!=0 || c!=0)
    {
        int p = a&1;
        int q = b&1;
        int r = c&1;

        if(r)
        {
            if(!p && !q)
                ans++;
        }
        else
        {
            if(p)
                ans++;
            
            if(q)
                ans++;
        }

        a = a>>1;
        b = b>>1;
        c = c>>1;
    }    

    return ans;
}
int main()
{
    cout << "Ans: " << minFlips(2,6,5) << endl;
}