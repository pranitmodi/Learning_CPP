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
class Trie {
public:
    TrieNode* root;
    Trie() {
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

        if(root->children[index] == NULL)
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        else
            child = root->children[index];

        insertWord(child,word.substr(1));
    }

    bool searchWord(TrieNode* root, string word)
    {
        if(word.length() == 0)
            return root->isTerminal;

        int index = word[0] - 'a';

        if(root->children[index] != NULL)
            return searchWord(root->children[index],word.substr(1));
        else
            return false;
    }

    bool starts(TrieNode* root, string word)
    {
        if(word.length() == 0)
            return true;

        int index = word[0] - 'a';

        if(root->children[index] != NULL)
            return starts(root->children[index],word.substr(1));
        else
            return false;
    }

    void insert(string word) {
        insertWord(root,word);
    }
    
    bool search(string word) {
        return searchWord(root,word);
    }
    
    bool startsWith(string prefix) {
        return starts(root,prefix);
    }
};