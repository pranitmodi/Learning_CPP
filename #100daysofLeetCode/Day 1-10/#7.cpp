// 116 Populating Next Right Pointers in Each Node
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root == NULL)
            return root;
            
        queue<Node*> qt;
        qt.push(root);
        qt.push(NULL);
        while(!qt.empty())
        {
            Node* temp = qt.front();
            qt.pop();
            if(temp!=NULL)
            {
                temp->next = qt.front();
                if(temp->left != NULL)
                {
                    qt.push(temp->left);
                    qt.push(temp->right);
                }
            }
            else
            {
                if(!qt.empty())
                    qt.push(NULL);
            }
        }    

        return root;
    }
};