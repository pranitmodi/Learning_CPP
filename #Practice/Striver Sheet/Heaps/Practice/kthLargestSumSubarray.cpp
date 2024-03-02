#include <bits/stdc++.h>
using namespace std;
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int,vector<int>,greater<int>> mini;
	for(int i=0; i<arr.size(); i++)
	{
		int sum = arr[i];
		for(int j=i+1; j<arr.size(); j++)
        {
            sum += arr[j];

            if(k>0)
            {
                mini.push(sum);
                k--;
            }
            else
            {
                if(mini.top()<sum)
                {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }

        return mini.top();
	}
}