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
void buildLevelOrder(Node *&root)
{
    int data;
    cout << "Enter data for the root: ";
    cin >> data;

    root = new Node(data);
    queue<Node*> qt;
    qt.push(root);

    while(!qt.empty())
    {
        Node *temp = qt.front();
        qt.pop();

        cout << "Enter data for the left of " << temp->data << ": " << endl;
        cin >> data;

        if(data != -1)
        {
            temp->left = new Node(data);
            qt.push(temp->left);
        }

        cout << "Enter data for the right of " << temp->data << ": " << endl;
        cin >> data;

        if(data != -1)
        {
            temp->right = new Node(data);
            qt.push(temp->right);
        }
    }
}

// 543
// Diameter
// 1. it can be in the left sub-tree
// 2. it can be in the right sub-tree
// 3. it can be height of left subtree + height of right subtree + 1

pair<int,int> diameter(Node *root)
{
    if(root == NULL)
    {
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameter(root->left);
    pair<int,int> right = diameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(op1, max(op2,op3));
    ans.second = max(left.second,right.second) + 1;
    return ans;
}
int main()
{
    Node *root;
    buildLevelOrder(root);
    pair<int,int> ans;
    ans = diameter(root);
    cout << "Diameter: " << (ans.first-1) << endl; //the length of the paths in between, not nodes
}