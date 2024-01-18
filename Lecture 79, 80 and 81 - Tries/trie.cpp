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
class Trie
{
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0'); // root node will be the null character
            cout << "yess" << endl;
        }

        void insertUtil(TrieNode *root, string word)
        {
            if(word.length() == 0)
            {
                root->isTerminal = true;
                return;
            }

            // Assumption: word will be in upper case
            int index = word[0] - 'A';
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

            insertUtil(child,word.substr(1));
        }

        void removeUtil(TrieNode* root, string word)
        {
            if(word.length() == 0)
            {
                cout << "not Found" << endl;
                return;
            }
            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL)
            {
                child = root->children[index];
                if(word.length() == 1)
                {
                    child->isTerminal = false;
                }
                else
                    removeUtil(child,word.substr(1));
            }
            else    
                cout << "Not Found!" << endl;
        }

        bool searchUtil(TrieNode* root, string word)
        {
            if(word.length() == 0)
            {
                return(root->isTerminal);
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL)
            {
                child = root->children[index];
                return searchUtil(child,word.substr(1));
            }
            else    
                return false;
        }

        bool startsWithUtil(TrieNode* root, string word)
        {
            if(word.length() == 0)
            {
                return true;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL)
            {
                child = root->children[index];
                return startsWithUtil(child,word.substr(1));
            }
            else    
                return false;
        }

        void insertWord(string word)
        {
            insertUtil(root,word);
        }

        bool startsWith(string word)
        {
            return startsWithUtil(root,word);
        }

        bool searchWord(string word)
        {
            return searchUtil(root,word);
        }

        void removeWord(string word)
        {
            removeUtil(root,word);
        }
};

int main()
{
    Trie* t = new Trie();
    t->insertWord("OKAY");
    cout << "preset OKAY?: " << t->searchWord("OKAY") << endl;

    t->insertWord("TIME");
    cout << "Time Present?: " << t->searchWord("TIME") << endl;
    cout << "Tim Present?: " << t->searchWord("TIM") << endl;

    t->removeWord("OKAY");
    cout << "preset OKAY?: " << t->searchWord("OKAY") << endl;
    cout << "preset?: " << t->searchWord("OKAYE") << endl;
}