// 632 - HARD
#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data;
        int row;
        int col;

        node(int data, int row, int col)
        {
            this->data = data;
            this->row = row;
            this->col = col;
        }
};
class compare
{
    public: 
        bool operator() (node* a, node* b)
        {
            return a->data > b->data;
        }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        priority_queue<node*,vector<node*>,compare> qt;
        for(int i=0; i<nums.size(); i++)
        {
            maxi = max(maxi,nums[i][0]);
            node* t = new node(nums[i][0],i,0);
            qt.push(t);
        }
        mini = qt.top()->data;

        vector<int> ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        
        while(qt.size() == nums.size())
        {
            node* temp = qt.top();
            qt.pop();

            mini = temp->data;

            if((ans[1]-ans[0]) > (maxi-mini))
            {
                ans[1] = maxi;
                ans[0] = mini;
            }

            if((temp->col + 1) < nums[temp->row].size())
            {
                maxi = max(nums[temp->row][temp->col + 1],maxi);

                temp->data = nums[temp->row][temp->col + 1];
                temp->col = temp->col + 1;
                qt.push(temp);
            }
            else
                break;
        }

        return ans;
    }
};