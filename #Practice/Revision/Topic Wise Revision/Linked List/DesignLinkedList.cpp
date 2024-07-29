// 707
#include <bits/stdc++.h>
using namespace std;
class Node
{
    public: 
        int val;
        Node *next;

        Node(int val)
        {
            this->val = val;
            this->next = NULL;
        }
};
class MyLinkedList {
public:
    Node *head;
    int len;
    MyLinkedList() {
        head = NULL;
        len = 0;
    }
    
    // void print()
    // {
    //     Node *temp = head;
    //     while(temp != NULL)
    //     {
    //         cout << temp->val << " ";
    //         temp = temp->next;
    //     }
    //     cout << endl;
    // }

    int get(int index) 
    {
        Node *temp = head;
        int c = 0;

        while(c<index && temp!=NULL)
        {
            c++;
            temp = temp->next;
        }

        if(c == index && temp!=NULL)
            return temp->val;
        
        return -1;
        
    }
    
    void addAtHead(int val) 
    {
        Node *temp = new Node(val);
        if(head == NULL)
            head = temp;
        else
        {
            temp->next = head;
            head = temp;
        }
        // print();
        len++;
    }
    
    void addAtTail(int val) 
    {   
        Node *temp = new Node(val);
        if(head == NULL)
            head = temp;
        else
        {
            Node *temp = head;
            while(temp->next != NULL)
                temp = temp->next;

            Node *n1 = new Node(val);
            temp->next = n1;
        }    
        // print();
        len++;
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index > len)
            return;
        if(index == 0)
        {
            addAtHead(val);
            return;
        }
        int c = 1;
        Node *temp = head;

        while(c<index && temp->next != NULL)
        {
            c++;
            temp = temp->next;
        }

        if(c == index)
        {
            Node *n1 = new Node(val);
            Node *temp2 = temp->next;
            temp->next = n1;
            n1->next = temp2;
        }
        // print();
        len++;
    }
    
    void deleteAtIndex(int index) 
    {
        if((index+1) > len)
            return;
        if(index == 0)
        {
            head = head->next;
            return;
        }    

        int c = 1;
        Node *temp = head;

        while(c<index && temp->next != NULL)
        {
            c++;
            temp = temp->next;
        }

        if(c == index)
        {
            Node *n1 = temp->next;
            if(n1->next == NULL)
            {
                temp->next = NULL;
            }
            else
            {
                temp->next = n1->next;
            }
        }
        // print();
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */