#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

// left nodes
void leftNodes(Node *root, vector<int> &ans)
{
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL)
    {
        return;
    }

    ans.push_back(root->data);

    if(root->left != NULL)
        leftNodes(root->left,ans);
    else
        leftNodes(root->right,ans);
}

// the bottom part the leaf nodes
void leafNodes(Node *root, vector<int> &ans)
{
    if(root == NULL)
        return;

    leafNodes(root->left,ans);

    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    leafNodes(root->right,ans);
}

// right nodes but in reverse
void rightNodes(Node *root, vector<int> &ans)
{
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL)
    {
        return;
    }

    if(root->right != NULL)
        rightNodes(root->right,ans);
    else
        rightNodes(root->left,ans);
    ans.push_back(root->data);

}
void buildLevelOrder(Node *&root)
{
    int data;
    cout << "Enter data for the root node: " << endl;
    cin >> data;

    root = new Node(data);
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter data for the left of " << temp->data << ": " << endl;
        cin >> data;

        if(data != -1)
        {
            temp->left = new Node(data);
            q.push(temp->left);
        }

        cout << "Enter data for the right of " << temp->data << ": " << endl;
        cin >> data;

        if(data != -1)
        {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
}
int main()
{
    Node *root;
    buildLevelOrder(root);
    vector<int> ans;
    leftNodes(root,ans);
    leafNodes(root,ans);
    rightNodes(root->right,ans);

    for(int i:ans)
    {
        cout << i << " ";
    }
    cout << endl;
}