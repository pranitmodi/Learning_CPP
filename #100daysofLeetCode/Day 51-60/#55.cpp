// 500. Keyboard Row
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    void add_elem(unordered_map<char,int> &m , string temp,int x)
    {
        for (int i=0; i< temp.length();i++)
            m[temp[i]] = x;
        
    }
    vector<string> findWords(vector<string>& words) 
    {
        string temp1 = "qwertyuiopQWERTYUIOP";
        string temp2 = "asdfghjklASDFGHJKL";
        string temp3 = "zxcvbnmZXCVBNM";
        
        unordered_map<char,int> m;
        
        add_elem(m,temp1,0);
        add_elem(m,temp2,1);
        add_elem(m,temp3,2);
        
        bool visited;
        vector<string> sol;
        
        for (string &word : words){
            visited = true;
            for (int i = 1; i < word.size();i++){
                if (m[word[i]] != m[word[0]]){
                    visited = false;
                    break;
                }
            }
            if (visited)
                sol.push_back(word);
        }
        return sol;
        
        
    }
};