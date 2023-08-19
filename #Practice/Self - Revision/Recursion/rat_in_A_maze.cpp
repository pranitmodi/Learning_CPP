#include <bits/stdc++.h>
using namespace std;
bool validate(int x, int y, int n, vector<vector<int>> &tab, vector<vector<int>> &arr)
{
    if((x>=0 && x<n) && (y>=0 && y<n) && tab[x][y] == 0 && arr[x][y] == 1)
        return true;
    return false;
}
void phasGaya(int x, int y, int n, vector<vector<int>> &tab, vector<string> &ans, vector<vector<int>> &arr, string &str)
{
    if(x == n-1 && y == n-1)
    {
        ans.push_back(str);
        return;
    }

    tab[x][y] = 1;

    int newx = x + 1;
    int newy = y;
    if(validate(newx,newy,n,tab,arr))
    {
        str.push_back('D');
        phasGaya(newx,newy,n,tab,ans,arr,str);
        str.pop_back();
    }

    int newx = x - 1;
    int newy = y;
    if(validate(newx,newy,n,tab,arr))
    {
        str.push_back('U');
        phasGaya(newx,newy,n,tab,ans,arr,str);
        str.pop_back();
    }

    int newx = x;
    int newy = y - 1;
    if(validate(newx,newy,n,tab,arr))
    {
        str.push_back('L');
        phasGaya(newx,newy,n,tab,ans,arr,str);
        str.pop_back();
    }

    int newx = x;
    int newy = y + 1;
    if(validate(newx,newy,n,tab,arr))
    {
        str.push_back('R');
        phasGaya(newx,newy,n,tab,ans,arr,str);
        str.pop_back();
    }

    tab[x][y] = 0;
}
int main()
{

}