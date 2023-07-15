#include <bits/stdc++.h> 
using namespace std;
long long sumOfMaxAndMin(int *nums, int n, int k) 
{
	deque<int> mini;
    mini.push_back(0);
    deque<int> maxi;
    maxi.push_back(0);
    long long sum = 0;

    for(int i=1; i<k; i++)
    {
        if(nums[i] > nums[maxi.front()])
        {
            maxi.push_front(i);
        }
        else
        {
            while(nums[maxi.back()] < nums[i])
                maxi.pop_back();
            maxi.push_back(i);
        }

        if(nums[i] < nums[mini.front()])
        {
            mini.push_front(i);
        }
        else
        {
            while(nums[mini.back()] > nums[i])
                mini.pop_back();
            mini.push_back(i);
        }
    }

    for(int i=k; i<n; i++)
    {
        sum = sum + nums[maxi.front()] + nums[mini.front()];
        while(!maxi.empty() && i - maxi.front() >= k)
        {
			maxi.pop_front();
		}

        while(!mini.empty() && i - mini.front() >= k)
        {
			mini.pop_front();
		}

		//cout << "after: " << nums[maxi.front()] << " " <<  nums[mini.front()] << endl;

        if(maxi.empty() || nums[i] > nums[maxi.front()])
        {
            maxi.push_front(i);
        }
        else
        {
            while(nums[maxi.back()] < nums[i])
                maxi.pop_back();
            maxi.push_back(i);
        }

        if(mini.empty() || nums[i] < nums[mini.front()])
        {
            mini.push_front(i);
        }
        else
        {
            while(nums[mini.back()] > nums[i])
                mini.pop_back();
            mini.push_back(i);
        }
    }
    sum = sum + nums[maxi.front()] + nums[mini.front()];
    return sum;
}
int main()
{
    int arr[] = {6, 13, 3, 11, 7, 6, 15} ;
    cout << "Sum: " << sumOfMaxAndMin(arr,7,1) << endl;
}
