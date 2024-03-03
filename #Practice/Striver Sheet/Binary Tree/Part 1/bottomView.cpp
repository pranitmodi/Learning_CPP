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
class Solution {
  public:
    vector<int> bottomView(Node *root) 
    {
        map<int,int> m;
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        queue<pair<int,Node*>> qt;
        qt.push(make_pair(0,root));
        
        while(!qt.empty())
        {
            pair<int,Node*> p = qt.front();
            qt.pop();
            Node *temp = p.second;
            
            m[p.first] = temp->data;
            
            if(temp->left != NULL)
                qt.push(make_pair(p.first-1,root->left));
                
            if(temp->right != NULL)
                qt.push(make_pair(p.first+1,root->right));
        }
        
        for(auto i:m)
            ans.push_back(i.second);
        
        return ans;
        
    }
};