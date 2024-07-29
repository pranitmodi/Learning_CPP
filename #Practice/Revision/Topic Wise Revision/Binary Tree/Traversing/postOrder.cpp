// 145
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
void postOrder(Node *root)
{
    if(root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << "\t";
}
int main()
{
    Node *root;
    buildLevelOrder(root);
    postOrder(root);
}