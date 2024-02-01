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
int height(Node *root)
{
    if(root == NULL)
        return 0;

    return(max(height(root->left),height(root->right)) + 1);
}
int main()
{
    Node *root;
    buildLevelOrder(root);
    cout << "Height: " << height(root) << endl;
}
