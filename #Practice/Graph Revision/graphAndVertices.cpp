#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long count(int n) 
    {
        int w = ((n-1)*n)/2;
        return (long long) pow(2,w);
    }
};

// number of undirected graphs that can be created: 2^((n*(n-1))/2)