#include <bits/stdc++.h>
using namespace std;

// Approach 1
vector<int> findTwoElement(vector<int> arr, int n) 
{
    sort(arr.begin(),arr.end());
    int p = -1;
    int w = 1;
    
    for(int i=0; i<arr.size()-1; i++)
    {
        if(arr[i] == arr[i+1])
            p = arr[i];
        else if(arr[i] == w)
            w++;
    }
    
    if(arr[arr.size()-1] == w)
        w++;
    
    vector<int> ans={p,w};
    return ans;
}

// Approach 2
// sum of n numbers - n(n+1) / 2
// sum of square of n numbers - n(n+1)(2n + 1) / 6
vector<int> findTwoElement(vector<int> arr, int n) 
{
    long long sum = (n * (n+1)) / 2;
    long long squareSum = (n * (n+1) * ((2 * n) + 1))/6;

    long long sum2 = 0;
    long long squareSum2 = 0;
    for(int i=0; i<arr.size(); i++)
    {
        sum2 += arr[i];
        squareSum2 += ((long long)arr[i] * (long long)arr[i]);
    }

    int diffOfAnswers = sum2 - sum; // (repeated - missing)
    int diffOfSquareOfAnswers = squareSum2 - squareSum; // (repeated^2 - missing^2)

    int sumOfAnswers = diffOfSquareOfAnswers / diffOfAnswers;
    int repeated = (diffOfAnswers + sumOfAnswers) / 2;
    int missing = sumOfAnswers - repeated;

    return {repeated,missing};
}
