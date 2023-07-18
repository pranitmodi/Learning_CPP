#include <bits/stdc++.h>
using namespace std;
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};
vector<int> bottomView(Node *root)
{
    queue<pair <Node*, int> >q; // No need to store according to levels, we just need the data of the first node at each position
    map <int,int> nodes;
    vector<int> ans;

    if(root == NULL)
        return ans;

    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair <Node*, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;

        nodes[hd] = frontNode->data;

        if(frontNode->left != NULL)
            q.push(make_pair(frontNode->left,hd-1));

        if(frontNode->right != NULL)
            q.push(make_pair(frontNode->right,hd+1));

    }

    for(auto i:nodes)
    {
        ans.push_back(i.second);
    }
    return ans;
}