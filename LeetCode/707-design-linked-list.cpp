#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr){} 
};

class MyLinkedList {
public:
    
    Node* head;
    int size;
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= size)
            return -1;
        Node* cur = head;
        while(index--)
            cur = cur->next;
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        size++;
        if(head == nullptr){
            head = new Node(val);
            return;
        }
        Node* new_head = new Node(val);
        new_head->next = head;
        head = new_head;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        size++;
        if(head == nullptr){
            head = new Node(val);
            return;
        }
        Node* cur = head;
        while(cur->next != nullptr)
            cur = cur->next;
        cur->next = new Node(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size)
            return;
        
        if(index == size){
            addAtTail(val);
        }else if(index == 0){
            addAtHead(val);
        }else{
            Node* cur = head;
            while(--index)
                cur = cur->next;
            Node* new_node = new Node(val);
            new_node->next = cur->next;
            cur->next = new_node;
            size++;
        }  
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= size)
            return;
        size--;
        if(index == 0){
            Node* tmp = head;
            head = head->next;
            delete tmp;
            return;
        }
        Node* cur = head;
        while(--index)
            cur = cur->next;
        Node* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
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