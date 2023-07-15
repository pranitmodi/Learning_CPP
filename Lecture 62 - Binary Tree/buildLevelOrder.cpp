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
            // cout << "Created for " << data << endl;
        }
};
void buildLevelOrder(Node *&root)
{
    queue<Node*>q;
    int data;
    cout << "Enter data for node: ";
    cin >> data;

    root = new Node(data);
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter data for left of " << temp->data << ": ";
        cin >> data;
        if(data != -1)
        {
            temp->left = new Node(data);
            q.push(temp->left);
        }

        cout << "Enter data for right of " << temp->data << ": ";
        cin >> data;
        if(data != -1)
        {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }

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
    buildLevelOrder(root);

    cout << "Binary Tree in Level Order: " << endl;
    printLevelOrder(root);

    return 0;
}