// 146
#include <bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    class Node
    {
        public: 
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;

    // map stores the node in the linked list
    unordered_map<int, Node*> m;

    LRUCache(int capacity) 
    {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* newnode)
    {
        Node* temp = head -> next;

        newnode -> next = temp;
        newnode -> prev = head;

        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deleteNode(Node* delnode)
    {
        Node* prevv = delnode -> prev;
        Node* nextt = delnode -> next;

        prevv -> next = nextt;
        nextt -> prev = prevv;
    }
    
    int get(int key) 
    {
        // if already present we need to update thus delete only node in the doubly-linked list
        // deletion and updation happens from map as well as linked list
        if(m.find(key) != m.end())
        {
            Node* resNode = m[key];
            int ans = resNode -> val;

            m.erase(key);
            deleteNode(resNode);

            // updating
            addNode(resNode);

            m[key] = head -> next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(m.find(key) != m.end()) // if already present we need to update as it recent of least used
        {
            Node* curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }

        // if cap reached, deleting the least used node
        // from map as well as linked list
        if(m.size() == cap)
        {
            m.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        addNode(new Node(key, value));
        m[key] = head -> next;
    }
};