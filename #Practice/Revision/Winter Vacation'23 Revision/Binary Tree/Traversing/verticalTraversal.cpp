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
void verticalTraversal(Node *root,vector<int> &ans)
{
    map<int, map<int, vector<int>>> nodes;
    queue< pair<Node*, pair<int,int>>> q;
    
    if(root == NULL)
        return;

    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty())
    {
        pair<Node*, pair<int,int>> temp = q.front();
        q.pop();

        Node* n = temp.first;
        int level = temp.second.first;
        int pos = temp.second.second;

        nodes[pos][level].push_back(n->data);

        if(n->left != NULL)
        {
            q.push(make_pair(n->left,make_pair(level+1,pos-1)));
        }
        if(n->right != NULL)
        {
            q.push(make_pair(n->right,make_pair(level+1,pos+1)));
        }
    }

    for(auto i:nodes)
    {
        for(auto j:i.second)
        {
            for(auto k:j.second)
            {
                ans.push_back(k);
                cout << k << " ";
            }
        }
    }
    cout << endl;
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
    verticalTraversal(root,ans);
}