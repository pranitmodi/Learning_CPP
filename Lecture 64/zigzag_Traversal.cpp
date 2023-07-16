#include <bits/stdc++.h>
using namespace std;
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};

// Approach 1
vector<int> zigZagTraversal(Node* root)
{
    vector<int> ans;
    vector<int> w;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int c = 1;
    
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        
        if(temp == NULL)
        {   
            if(c%2 == 0)// pushing in reverse order
            {
                for(int i=w.size()-1; i>=0; i--)
                {
                    ans.push_back(w[i]);
                    w.pop_back();
                }
            }
            else
                w.clear();

            c++;
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            if(c&2 != 0)
                ans.push_back(temp->data); // pushing in same order
            w.push_back(temp->data);

            if(temp->left != NULL)
                q.push(temp->left);
            
            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
    
    return ans;
}

// Approach 2 - Better
vector<int> zigZagTraversal(Node* root)
{
    vector<int> result;
    if(root == NULL)
        return result;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;
    
    while(!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for(int i=0; i<size; i++)
        {
            Node *temp = q.front();
            q.pop();

            int index = leftToRight ? i : (size - i - 1);
            ans[index] = temp->data;

            if(temp->left != NULL)
                q.push(temp->left);
            
            if(temp->right != NULL)
                q.push(temp->right);
        }

        leftToRight = !leftToRight;
        for(auto i: ans)
            result.push_back(i);
    }
    return result;
}