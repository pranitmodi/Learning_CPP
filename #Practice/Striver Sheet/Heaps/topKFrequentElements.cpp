// 347
#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        int cnt;

        Node(int d, int c)
        {
            data = d;
            cnt = c;
        }
};
class compare
{
    public:

        bool operator() (Node *a,  Node *b)
        {
            return a->cnt > b->cnt;
        }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int,int> m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]]++;

        priority_queue<Node*,vector<Node*>,compare> mini;
        for(auto i:m)
        {
            if(k>0)
            {
                Node *n = new Node(i.first,i.second);
                mini.push(n);
                k--;
            }
            else
            {
                if(mini.top()->cnt < i.second)
                {
                    mini.pop();
                    Node *n = new Node(i.first,i.second);
                    mini.push(n);
                }
            }
        }

        vector<int> ans;
        while(mini.size()>0)
        {
            ans.push_back(mini.top()->data);
            mini.pop();
        }

        return ans;
    }
};