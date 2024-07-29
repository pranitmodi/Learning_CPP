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
void diagNodes(map<int, vector<int>> &nodes, Node *root, int hd)
{
    if(root == NULL)
        return;

    nodes[hd].push_back(root->data);

    diagNodes(nodes,root->left,hd-1);
    diagNodes(nodes,root->right,hd);
}
vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
    
    map<int, vector<int>> nodes;
    diagNodes(nodes,root,0);

    for (auto it = nodes.rbegin(); it != nodes.rend(); it++)
    {
        for(auto j:it->second)
        {
            ans.push_back(j);
        }
    }
}