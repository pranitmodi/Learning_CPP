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

// Step 1 and 2
Node* createParentMappint(map<Node*,Node*> &nodeToParent, int target, Node *root)
{
    if(root == NULL)
        return NULL;

    Node *ans = NULL;

    queue<Node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        
        if(temp->data == target)
            ans = temp;

        if(temp->left != NULL)
        {
            q.push(temp->left);
            nodeToParent[temp->left] = temp;
        }

        if(temp->right != NULL)
        {
            q.push(temp->right);
            nodeToParent[temp->right] = temp;
        }
    }
    return ans;
}

// Step 3
int burnTree(map<Node*,Node*> &nodeToParent, Node *root)
{
    int ans = 0;
    map<Node*,bool> visited;
    queue<Node*> q;

    q.push(root);
    visited[root] = true;

    while(!q.empty())
    {
        bool flag = false;
        int size = q.size();
        for(int i=0; i<size; i++)
        {
            Node *temp = q.front();
            q.pop();

            if((temp->left != NULL) && (!visited[temp->left]))
            {
                q.push(temp->left);
                visited[temp->left] = true;
                flag = true;
            }

            if((temp->right != NULL) && (!visited[temp->right]))
            {
                q.push(temp->right);
                visited[temp->right] = true;
                flag = true;
            }

            if((nodeToParent[temp] != NULL) && (!visited[nodeToParent[temp]]))
            {
                q.push(nodeToParent[temp]);
                visited[nodeToParent[temp]] = true;
                flag = true;
            }
        }
        if(flag == true)
            ans++;
    }
    return ans;
}


int minTime(Node* root, int target) 
{
    map<Node*, Node*> nodeToParent;
    Node *t = createParentMappint(nodeToParent,target,root);

    return burnTree(nodeToParent,t);
}