#include <iostream>
#include <vector>

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
    while(curr -> next != nullptr && curr -> data < x) 
        curr = curr -> next;

    tmp -> next = curr -> next;
    curr -> next = tmp;

    if(curr -> data > tmp -> data)
        swap(curr -> data, tmp -> data);
    return head;
}

void printList(node * head) {
    node * curr = head;
    while(curr != nullptr) {
        cout << curr -> data << " ";
        curr = curr -> next;
    }
    cout << endl;
}

void printMiddle(node * head) {
    if(head == nullptr)
        return;

    node * slow = head, * fast = head;
    while(fast != nullptr && fast -> next != nullptr) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    cout << slow -> data << endl;
}

void printMiddle2(node * head) {
    if(head == nullptr)
        return;
    
    int len = 1;
    node * curr = head;
    while(curr) {
        curr = curr -> next;
        len++;
    }

    curr = head;
    for(int i = 1; i < len / 2; i++)
        curr = curr -> next;

    cout << curr -> data << endl;
}

void printNthfromEnd(node * head, int n) {
    if(head == nullptr)
        return;
    
    int len = 0;
    node * curr = head;

    while(curr) {
        curr = curr -> next;
        len++;
    }

    if(len < n)
        return;

    curr = head;
    for(int i = 1; i < len - n + 1; i++)
        curr = curr -> next;

    cout << curr -> data << endl;
}

void printNthfromEnd2(node * head, int n) {
    if(head == nullptr)
        return;

    node * first = head, * second = head;

    for(int i = 0; i < n; i++)
        first = first -> next;

    while(first) {
        first = first -> next;
        second = second -> next;
    }

    cout << second -> data << endl;
}

node * revList(node * head) {
    vector < int > v;
    for(node * curr = head; curr != nullptr; curr = curr -> next)
        v.push_back(curr -> data);

    for(node * curr = head; curr != nullptr; curr = curr -> next) {
        curr -> data = v.back();
        v.pop_back();
    }

    return head;
}

node * reverse(node * head) {
    if(head == nullptr)
        return head;
    
    node * curr = head, * prev = nullptr;

    while(curr) {
        node * next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

node * revListRecur(node * head) {
    if(head == nullptr || head -> next == nullptr)
        return head;

    node * rest_head = revListRecur(head -> next);
    node * rest_tail = head -> next;
    rest_tail -> next = head;
    head -> next = nullptr;
    return rest_head;
}

node * revListRecur2(node * curr, node * prev) {
    if(curr == nullptr)
        return prev;

    node * next = curr -> next;
    curr -> next = prev; 
    return revListRecur2(next, curr);
}

void removeDuplicate(node * head) {
    if(head == nullptr)
        return;

    node * curr = head;
    while(curr && curr -> next) {
        if(curr -> data == curr -> next -> data) {
            node * tmp = curr -> next;
            curr -> next = curr -> next -> next;
            delete(tmp);
        } else
            curr = curr -> next;
    }
}

int main() {
    node * head = nullptr;
    head = sortedInsert(head, 10);
    head = sortedInsert(head, 20);
    head = sortedInsert(head, 15);
    head = sortedInsert(head, 30);
    head = sortedInsert(head, 0);
    
    printList(head);
    printMiddle(head);
    printMiddle2(head);
    printNthfromEnd(head, 2);
    printNthfromEnd2(head, 2);

    head = revList(head);
    printList(head);
    head = reverse(head);
    printList(head);
    head = revListRecur(head);
    printList(head);
    head = revListRecur2(head, nullptr);
    printList(head);

    head = sortedInsert(head, 10);
    printList(head);
    removeDuplicate(head);
    printList(head);

    return 0;
}