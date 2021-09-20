/*

XOR Linked Lists are Memory Efficient implementation of Doubly Linked Lists. 
An ordinary Doubly Linked List requires space for two address fields to store the addresses of previous and next nodes.
A memory-efficient version of Doubly Linked List can be created using only one space for the address field with every node. 
This memory efficient Doubly Linked List is called XOR Linked List or Memory Efficient Linked List as the list uses bitwise XOR operation to save space for one address. 
In the XOR linked list instead of storing actual memory addresses every node stores the XOR of addresses of previous and next nodes.

Hashing Solution :Traverse the list one by one and keep putting the node addresses in a Hash Table. 
At any point, if NULL is reached then return false and if next of current node points to any of the previously stored nodes in Hash then return true.

*/

#include <iostream>

using namespace std;

struct node {
    int data;
    struct node * next;
    node(int x) {
        data = x;
        next = nullptr;
    }
};

node * sortedInsert(node * head, int x) {
    node * tmp = new node(x);
    if(head == nullptr)
        return tmp;

    if(head -> data > x) {
        tmp -> next = head;
        return tmp;
    }
    node * curr = head;
    while(curr -> next != nullptr && curr -> next -> data < x) 
        curr = curr -> next;

    tmp -> next = curr -> next;
    curr -> next = tmp;

    // if(curr -> data > tmp -> data)
    //     swap(curr -> data, tmp -> data);
    return head;
}

// Floyd Cycle Finding Algorithm
bool detectloop(node* head) {
    node *slow_p = head, *fast_p = head;
  
    while (slow_p && fast_p && fast_p->next) 
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) 
            return true ;
    }
    return false  ;
} 

int main() {
    node * head = nullptr;
    head = sortedInsert(head, 10);
    head = sortedInsert(head, 20);
    head = sortedInsert(head, 15);
    head = sortedInsert(head, 30);
    head = sortedInsert(head, 0);

    cout << detectloop(head);
    return 0;
}