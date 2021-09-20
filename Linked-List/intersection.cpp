/*

Have a visited flag with each node. 
Traverse the first linked list and keep marking visited nodes. 
Now traverse the second linked list, If you see a visited node again then there is an intersection point, return the intersecting node. 
This solution works in O(m+n) but requires additional information with each node.

OR

Traverse the first linked list and store the addresses of visited nodes in a hash. 
Now traverse the second linked list and if you see an address that already exists in the hash then return the intersecting node.

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

int utility(int d, node* head1, node* head2) {
    node* current1 = head1;
    node* current2 = head2;
  
    for (int i = 0; i <= d - 1; i++) {
        if(current1 == NULL) 
            return -1;
        current1 = current1 -> next;
    }

    while(current1 !=  NULL && current2 != NULL) {
        if(current1 == current2) 
            return current1 -> data;
        current1 = current1->next;
        current2 = current2->next;
    }
    return -1;
}

int getCount(node * head) {
    int count = 0;
    node * curr = head;

    while(curr) {
        count++;
        curr = curr -> next;
    }

    return count;
}

int getIntesectionNode( node* head1, node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d; // difference 

    if(c1 > c2) {
        d = c1 - c2;
        return utility(d, head1, head2);
    } else {
        d = c2 - c1;
        return utility(d, head2, head1);
    }
}

int main() {
    node * head = nullptr, * head1 = nullptr;
    head = sortedInsert(head, 10);
    head = sortedInsert(head, 20);
    head = sortedInsert(head, 15);
    head = sortedInsert(head, 30);
    head = sortedInsert(head, 0);

    head1 = sortedInsert(head1, 15);
    head1 = sortedInsert(head1, 30);
    head1 = sortedInsert(head1, 0);

    cout << getIntesectionNode(head, head1);
    return 0;
}