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

// Approach 1
vector<int> leftView1(Node *root)
{
    vector <int> ans;
    if(root == NULL)
        return ans;

    map <int,int> nodes;
    queue < pair<Node*,int>> q;
    q.push(make_pair(root,0));

    while(!q.empty())
    {
        pair<Node*,int> temp = q.front();
        Node *frontNode = temp.first;
        int level = temp.second;

        if(nodes.find(level) == nodes.end())
        {
            nodes[level] = frontNode->data;
        }

        if(frontNode->left != NULL)
            q.push(make_pair(frontNode->left,level+1));

        if(frontNode->right != NULL)
            q.push(make_pair(frontNode->right,level+1));
    }

    for(auto i:nodes)
    {
        ans.push_back(i.second);
    }

    return ans;
}

// Approach 2
void leftView(Node *root, int level, vector<int> &ans)
{
    if(root == NULL)
        return;
    
    if(level == ans.size())
        ans.push_back(root->data);

    if(root->left != NULL)
        leftView(root->left,level+1,ans);

    if(root->right != NULL)
        leftView(root->right,level+1,ans);
}
vector<int> leftView2(Node *root)
{
    vector<int> ans;
    leftView(root,0,ans);
    return ans;
}