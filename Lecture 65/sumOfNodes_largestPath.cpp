#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void sumCal(Node *root, pair<int,int> &nodes, int level, int sum)
{
    if(root == NULL)
        return;
        
    sum = sum + root->data;
    if(nodes.first < level)
    {
        nodes.first = level;
        nodes.second = sum;
    }
    else if(nodes.first == level && sum > nodes.second)
    {
        nodes.second = sum;
    }
    
    sumCal(root->left,nodes,level+1,sum);
    sumCal(root->right,nodes,level+1,sum);
}
int sumOfLongRootToLeafPath(Node *root)
{
    pair<int,int> nodes = {0,0};
    sumCal(root,nodes,1,0);
    return nodes.second;
}