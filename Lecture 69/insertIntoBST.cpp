#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data)
        {
            this->data = data;
            left = right = NULL;
        }
};
Node* insertIntoTree(Node *root, int d)
{
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if(d < root->data)
        root->left = insertIntoTree(root->left,d);
    else if(d > root->data)
        root->right = insertIntoTree(root->right,d); 

    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while(data != -1)
    {
        root = insertIntoTree(root, data);
        cin >> data;
    }
    cout << "Input Completed!" << endl;
}

void printLevelOrder(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";

            if(temp->left != NULL)
                q.push(temp->left);

            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = NULL;
    cout << "Enter Data: ";
    takeInput(root);

    printLevelOrder(root);
}