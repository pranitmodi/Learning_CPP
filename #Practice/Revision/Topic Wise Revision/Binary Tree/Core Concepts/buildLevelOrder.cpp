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
            this->right = NULL;
            this->left = NULL;
        }
};
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
// 102
void levelOrderTraversal(Node *root)
{
    queue<Node*> qt;
    qt.push(root);
    qt.push(NULL);

    cout << "Level Order: " << endl;

    while(!qt.empty())
    {
        Node *temp = qt.front();
        qt.pop();

        if(temp != NULL)
        {
            cout << temp->data << " ";
            if(temp->left != NULL)
                qt.push(temp->left);

            if(temp->right != NULL)    
                qt.push(temp->right);
        }
        else
        {
            cout << endl;
            if(!qt.empty())
                qt.push(NULL);
        }
    }
}
int main()
{
    Node *root;
    buildLevelOrder(root);
    levelOrderTraversal(root);
}