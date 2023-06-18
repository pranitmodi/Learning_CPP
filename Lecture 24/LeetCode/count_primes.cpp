// LeetCode
// 204. Count Primes
// Sieve of Eratosthenes

#include <bits/stdc++.h>
using namespace std;
int countPrimes(int n) 
{
    int count = 0;
    vector<bool> prime(n+1,true);

    prime[0] = prime[1] = false;
    for(int i=2; i<n; i++)
    {
        if(prime[i])
        {
            count++;
            for(int j=2*i; j<n; j=j+i)
            {
                prime[j] = false;
            }
        }
    }
    return count;
}
int main()
{
    int n;
    cout << "Enter the limit:";
    cin>>n;

    cout << "Number of Prime Numbers in between: " << countPrimes(n) << endl;
    return 0;
}