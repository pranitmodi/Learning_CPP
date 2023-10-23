// leetCode - 1207
#include <bits/stdc++.h>
using namespace std;
bool uniqueOccurrences(vector<int>& arr) 
{   
    map<int,bool> w;
    sort(arr.begin(),arr.end());
    for(int i=0; i<arr.size();)
    {
        int ele = arr[i];
        int c = 1;
        int j = i+1;
        while(j<arr.size() && arr[j] == ele)
        {
            c++;
            j++;
        }

        if(w[c] == true)
            return false;
        else
            w[c] = true;

        i = j;
    }
}
int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    cout << uniqueOccurrences(arr) << endl;
}