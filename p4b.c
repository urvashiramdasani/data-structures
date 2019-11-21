#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *head=NULL;
void rev()
{

}
struct node * newnode(struct node *n)
{
    n=(struct node *) malloc(sizeof(struct node));
    n->info=0;
    n->link=NULL;
    printf("\nNew node created successfully!");
}
void insertf(int val)
{
    struct node *n;
    n=newnode(n);
    if(head==NULL)
        head=n;
    n->info=val;
    n->link=head;
    head=n;
}
void insertl(int val)
{
    struct node *n;
    n=newnode(n);

}
void display()
{

}
void main()
{

}