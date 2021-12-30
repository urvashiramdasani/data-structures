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

void printList(node * head) {
    // if(head == nullptr)
    //     return;

    // cout << head -> data << " ";

    // for(node * p = head -> next; p != head; p = p -> next)
    //     cout << p -> data << " ";

    if(head == NULL)
        return;

    node * p = head;

    do {
        cout << p -> data << " ";
        p = p -> next;
    } while(p != head);

    cout << endl;
}

node * insertBeg(node * head, int x) {
    node * tmp = new node(x);

    if(head == nullptr)
        tmp -> next = tmp;
    else {
        node * curr = head;
        
        while(curr -> next != head)
            curr = curr -> next;

        curr -> next = tmp;
        tmp -> next = head;
    }

    return tmp;
}

node * insertBegEff(node * head, int x) {
    node * tmp = new node(x);
    
    if(head == nullptr) {
        tmp -> next = tmp;
        return tmp;
    }

    tmp -> next = head -> next;
    head -> next = tmp;
    int t = head -> data;
    head -> data = tmp -> data;
    tmp -> data = t;

    return head;
}

node * insertEnd(node * head, int x) {
    node * tmp = new node(x);

    if(head == nullptr) {
        tmp -> next = tmp;
        return tmp;
    }

    node * curr = head;
    
    while(curr -> next != head)
        curr = curr -> next;

    curr -> next = tmp;
    tmp -> next = head;

    return head;
}

node * insertEndEff(node * head, int x) {
    node * tmp = new node(x);

    if(head == nullptr) 
        tmp -> next = tmp;
    else {
        tmp -> next = head -> next;
        head -> next = tmp;
        int t = head -> data;
        head -> data = tmp -> data;
        tmp -> data = t;
    }

    return tmp;
}

node * deleteHead(node * head) {
    if(head == nullptr)
        return head;

    if(head -> next == head) {
        delete head;
        return nullptr;
    }

    node * curr = head;

    while(curr -> next != head) 
        curr = curr -> next;

    curr -> next = head -> next;
    head -> next = nullptr;
    delete head;

    return curr -> next;
}

node * deleteHeadEff(node * head) {
    if(head == nullptr)
        return head;

    if(head -> next == head) {
        delete head;
        return nullptr;
    }

    node * tmp = head -> next;
    head -> data = tmp -> data;
    head -> next = tmp -> next;
    delete tmp;

    return head;
}

node * deleteKth(node * head, int k) {
    if(head == nullptr)
        return head;

    if(k == 1)
        return deleteHeadEff(head);

    node * curr = head;

    for(int i = 0; i < k - 2; i++) 
        curr = curr -> next;

    node * tmp = curr -> next;
    curr -> next = tmp -> next;
    delete tmp;

    return head;
}

int main() {
    node * head = nullptr;

    head = insertBeg(head, 10);
    printList(head);
    head = insertBegEff(head, 20);
    printList(head);
    head = insertEnd(head, 15);
    printList(head);
    head = insertEndEff(head, 30);
    printList(head);
    head = deleteHead(head);
    printList(head);
    head = deleteHeadEff(head);
    printList(head);
    head = deleteKth(head, 2);
    printList(head);

    return 0;
}

// 10 
// 20 10 
// 20 10 15 
// 20 10 15 30 
// 10 15 30 
// 15 30 
// 15 