// Advantages - no preallocation of nodes, insertion and deletion
// Binary search O(nlogn) is not allowed in linkedlists. Advance linked lists called skip lists do some extra overhead and search faster.

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *head=NULL;
struct node * newnode(struct node *n)
{
    n=(struct node *) malloc(sizeof(struct node));
    n->info=0;
    n->link=NULL;
    printf("\nNew node created successfully!");
    return n;
}
void insertf(int val)
{
    struct node *n;
    n=newnode(n);
    n->info=val;
    if(head==NULL)
    {
        head=n;
    }
    else
    {
        n->link=head;
        head=n;   
    }
}
void insertl(int val)
{
    struct node *n;
    n=newnode(n);
    struct node *temp;
    temp=head;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=n;
    n->info=val;
    n->link=NULL;
}
void insert_pos()
{
    int val,pos;
    char choice;
    if(head==NULL)
    {
        printf("\nList is Empty!");
        return;
    }
    printf("\nEnter the value you want to add: ");
    scanf("%d",&val);
    fflush(stdin);
    printf("\nEnter the node value: ");
    scanf("%d",&pos);
    printf("\nEnter b for before and a for after: ");
    scanf("%c",&choice);
    struct node *n;
    n=newnode(n);
    struct node *temp,*current;
    temp=head;
    current=head;
    while(temp->info!=pos && temp->link!=NULL)
    {
        current=temp;
        temp=temp->link;
    }
    if(ch=='b' || ch=='B')
    {
        current->link=n;
        n->link=temp;
    }
    else if(ch=='a' || ch=='A')
    {
        current=temp;
        temp=temp->link;
        current->link=n;
        n->link=temp;
    }
    n->info=val;
}
void delete(int val)
{
    if(head==NULL)
    {
        printf("List is Empty!");
        return;
    }
    struct node *temp,*current;
    temp=head;
    while(temp->link!=NULL && temp->info!=val)
    {
        current=temp;
        temp=temp->link;
    }
    if(temp->info==head->info)
        head=head->link;
    else
    {
        if(temp->info!=val)
            printf("Element not found");
        else
        {
            current->link=temp->link;
            free(temp);
        }   
    }
}
void show()
{
    struct node *temp;
    temp=head;
    while(temp->link!=NULL)
    {
        printf("\t%d",temp->info);
        temp=temp->link;
    }
    printf("\t%d",temp->info);
}
void main()
{
    int ch,val,pos;
    char choice;
    do
    {
        printf("\n1. Insert at beggining\n2. Insert at last\n3. Insert in between\n4. Delete\n5. Display\n6. Quit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter the value you want to add: ");
                    scanf("%d",&val);
                    insertf(val);
                    break;
            case 2: printf("\nEnter the value you want to add: ");
                    scanf("%d",&val);
                    insertl(val);
                    break;
            case 3: insert_pos();
                    break;
            case 4: printf("\nEnter the node value you want to delete: ");
                    scanf("%d",&val);
                    delete(val);
                    break;
            case 5: show();
                    break;
            case 6: ch=6;
                    break;
            default: printf("\nInvalid choice!");
                        break;
        }
    } while (ch!=6);
}
