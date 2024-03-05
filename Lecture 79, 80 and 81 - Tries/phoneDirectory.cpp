#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch)
        {
            this->data = ch;
            for(int i=0; i<26; i++) 
                children[i] = NULL;

            isTerminal = false;
        }
};

// normal trie implementation with insertion
class Trie
{
    public:
        TrieNode* root;

        Trie()
        {
            root = new TrieNode('\0');
        }

        void insertWord(TrieNode* root, string word)
        {
            if(word.length() == 0)
            {
                root->isTerminal = true;
                return;
            }

            int index = word[0] - 'a';
            TrieNode* child;

            if(root->children[index] != NULL)
            {
                child = root->children[index];
            }
            else
            {
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            insertWord(child,word.substr(1));
        }

        void insert(string word)
        {
            insertWord(root,word);
        }
};

void store(vector<string> &str, TrieNode* root, string s)
{
    s.push_back(root->data); // always pushing to the string s
    if(root->isTerminal)
        str.push_back(s); // whenerver an ending of new word reached

    // for each node checking if its child nodes exist, if they do recursive call
    for(int i=0; i<26; i++)
    {
        if(root->children[i] != NULL)
            store(str,root->children[i],s);
    }
}

vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    Trie* t = new Trie();
    for(int i=0; i<n; i++)
    {
        t->insert(contact[i]);
    }

    vector<vector<string>> ans;
    string w = "";
    TrieNode* temp = t->root;

    for(int i=0; i<s.length(); i++) // for all the chars of string s
    {
        vector<string> str;
        int index = s[i] - 'a';
        if(temp->children[index] != NULL) // as at root -> '\0' null character is stored
        {
            temp = temp->children[index]; //after checking send the next character
            store(str,temp,w);

            ans.push_back(str);
            w.push_back(s[i]);
        }
        else
            break;
    }

    vector<string> str ={"0"}; // for correct printing format
    int l = s.length() - ans.size();
    for(int i=1; i<=l; i++)
    {
        ans.push_back(str);
    }

    return ans;
}

int main()
{
    string contact[] = {"geeikistest", "geeksforgeeks", "geeksfortest"};
    int n = 3;
    string s = "geeips";
    vector<vector<string>> ans = displayContacts(n,contact,s);
}