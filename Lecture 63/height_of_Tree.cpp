#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
// Approach 1 - Using Ordered Printing way and counting all the NULL
int height(struct Node* node)
{
    queue<Node*>q;
    q.push(node);
    q.push(NULL);
    int c = 0;
    
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        
        if(temp == NULL)
        {
            c++;
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            if(temp->left != NULL)
                q.push(temp->left);
            
            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
    return c;
}

// Approach 2 - Using Recursion
int height(struct Node* node)
{
    if(node == NULL)
        return 0;

    return(max(height(node->left),height(node->right)) + 1);
}
int main()
{



    return 0;
}