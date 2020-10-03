#include <bits/stdc++.h>
using namespace std;

struct node {
  int data, degree;
  node *child, *sibling, *parent;
};

node * createnode(int val) {
  node * newnode = new node;
  newnode->data = val;
  newnode->degree = 0;
  newnode->sibling = newnode->child = newnode->parent = NULL;
  return newnode;
};

list<node*> unionheap(list<node*> hp, list<node*> tmp) {
  list <node*> l;
  list <node*>::iterator i = hp.begin();
  list <node*>::iterator j = tmp.begin();

  while(i != hp.end() && j != tmp.end()) {
    if((*i)->degree <= (*j)->degree) {
      l.push_back(*i);
      i++;
    } else {
      l.push_back(*j);
      j++;
    }
  }
  while(i != hp.end()) {
    l.push_back(*i);
    i++;
  }
  while(j != tmp.end()) {
    l.push_back(*j);
    j++;
  }

  // list <node*>::iterator k = l.begin();
  // while(k != l.end()) {
  //   cout<<(*k)->data<<" ";
  //   k++;
  // }
  return l;
};

node * merge(node *n1, node *n2) {
  if(n1->data > n2->data) swap(n1, n2);
  n2->parent = n1;
  n2->sibling = n1->child;
  n1->child = n2;
  n1->degree++;

  return n1;
};

list<node*> adjust(list<node*> tmp) {
  if(tmp.size() <= 1) return tmp;
  list <node*>::iterator i,j,k;
  i = j = k = tmp.begin();

  if(tmp.size() == 2) {
    j = i;
    j++;
    k = tmp.end();
  } else {
    j++;
    k = j;
    k++;
  }

  while(i != tmp.end()) {
    if(j == tmp.end()) i++;
    else if((*i)->degree < (*j)->degree) {
      i++;
      j++;
      if(k != tmp.end()) k++;
    } else if(k != tmp.end() && (*i)->degree == (*j)->degree && (*i)->degree == (*k)->degree ) {
      i++;
      j++;
      k++;
    } else if((*i)->degree == (*j)->degree) {
      node * h;
      *i = merge(*i, *j);
      j = tmp.erase(j);
      if(k != tmp.end()) k++;
    }
  }
  list <node*>::iterator l = tmp.begin();
  // while(l != tmp.end()) {
  //   cout<<(*l)->data<<" ";
  //   l++;
  // }
  return tmp;
};

list<node*> insertnode(list<node*> hp, node* newnode) {
  list<node*> tmp;
  tmp.push_back(newnode);
  tmp = unionheap(hp, tmp);
  return adjust(tmp);
};

list<node*> insert(list<node*> hp, int data) {
  node* tmp = createnode(data);
  return insertnode(hp, tmp);
};

node* findmin(list <node*> hp) {
  list <node*>::iterator i = hp.begin();
  node* tmp = *i;
  while(i != hp.end()) {
    if((*i)->data < tmp->data) tmp = *i;
    i++;
  }
  return tmp;
};

list <node*> remove_min_tree(node * tmp) {
  list <node*> heap;
  node * h = tmp->child;
  node * n;

  while(h) {
    n = h;
    h = h->sibling;
    n->sibling = NULL;
    heap.push_front(n);
  }

  return heap;
};

void print_tree(node * tree) {
  while(tree) {
    cout<<tree->data<<" ";
    print_tree(tree->child);
    tree = tree->sibling;
  }
};

void print_heap(list <node*> heap) {
  list <node*>::iterator i = heap.begin();
  while(i != heap.end()) {
    print_tree(*i);
    i++;
  }
};

list <node*> deletemin(list <node*> hp) {
  node * tmp = findmin(hp);
  list <node*>::iterator i = hp.begin();
  list <node*> heap, h;

  while(i != hp.end()) {
    if(*i != tmp) heap.push_back(*i);
    i++;
  }
  h = remove_min_tree(tmp);
  heap = unionheap(heap, h);
  heap = adjust(heap);
  return heap;
};

int main() {
  int val = 1; int key; 
  list<node*> hp;
  node * n;
  while(val) {
    cout<<"\n1. Add a node\n2. Find Minimum\n3. Delete Minimum\n4. Display Heap\n5. Exit\n";
    int ch; cin>>ch;
    switch(ch) {
      case 1: cout<<"Enter the value to be added : ";
              cin>>key;
              hp = insert(hp, key);
              break;
      case 2: n = findmin(hp);
              cout<<"The minimum element of the heap is "<<n->data;
              break;
      case 3: hp = deletemin(hp);
              break;
      case 4: print_heap(hp);
              break;
      case 5: val = 0;
              break;
      default: val = 0; 
              break;
    }
  }
}
