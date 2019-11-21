//Implementing Doubly Linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* right;
    struct node* left;
};
struct node* head=NULL;
struct node* newnode(struct node* n)
{
    n=(struct node*) malloc(sizeof(struct node*));
    n->right=NULL;
    n->left=NULL;
    n->data=0;
}
void insertf(int val)
{
    struct node* n=newnode(n);
    struct node* temp;
    if(head==NULL)
    {
        n->data=val;
        n->right=NULL;
        n->left=NULL;
        head=n;
    }
    else
    {
        temp=head;
        n->data=val;
        n->right=temp;
        temp->left=n;
        n->left=NULL;
        head=n;
    }
}
void insertl(int val)
{
    struct node* n=newnode(n);
    struct node* temp;
    if(head==NULL)
    {
        n->data=val;
        n->right=NULL;
        n->left=NULL;
        head=n;
    }
    else
    {
        temp=head;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        n->data=val;
        n->right=NULL;
        n->left=temp;
        temp->right=n;
    }
}
void insert_pos(int val)
{
    struct node* n=newnode(n);
    n->data=val;
    struct node* temp,*current;
    int pos,count=1;
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    if(head==NULL && pos!=1)
    {
        printf("\nLinked list is empty!");
        return;
    }
    else if(pos==1 && head==NULL)
    {
        n->data=val;
        n->left=NULL;
        n->right=NULL;
        head=n;
    }
    else if(head!=NULL && pos==1)
    {
        n->right=head;
        head->left=n;
        n->left=NULL;
        head=n;
    }
    else 
    {
        temp=head;
        current=head;
        while(temp->right!=NULL)
        {
            current=temp;
            temp=temp->right;
            count++;
            if(count==pos)
            {
                current->right=n;
                n->left=current;
                n->right=temp;
                temp->left=n;
            }
        }
        if(temp->right==NULL && pos==count+1)
        {
            temp->right=n;
            n->left=temp;
            n->right=NULL;
        }
    }
    if(pos!=count+1)
    {
        printf("\nInvalid Position");
        return;
    }
}
void deletef()
{
    struct node* temp;
    if(head==NULL)
    {
        printf("\nLinked List is Empty!");
        return;
    }
    else
    {
        temp=head;
        if(temp->right==NULL && temp->left==NULL)
        {
            head=NULL;
            free(temp);
            return;
        }
        else
        {
            head=head->right;
            head->left=NULL;
            free(temp);
        }
    }
}
void deletel()
{
    struct node* temp,*current;
    if(head==NULL)
    {
        printf("\nLinked List is Empty!");
        return;
    }
    else
    {
        temp=head;
        current=head;
        if(temp->right==NULL && temp->left==NULL)
        {
            head=NULL;
            free(temp);
            return;
        }
        while(temp->right!=NULL)
        {
            current=temp;
            temp=temp->right;
        }
        temp->left=NULL;
        current->right=NULL;
        free(temp);
    }
}
void delete_pos()
{
    struct node* temp,*current,* ahead;
    int pos,count=1;
    if(head==NULL)
    {
        printf("\nLinked List is Empty!");
        return;
    }
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    if(head!=NULL && pos==1)
    {
        deletef();
    }
    else
    {
        temp=head;
        current=head;
        if(temp->right==NULL && temp->left==NULL)
        {
            head=NULL;
            free(temp);
            return;
        }
        while(temp->right!=NULL)
        {
            current=temp;
            temp=temp->right;
            count++;
            if(temp->right!=NULL && count==pos)
            {
                ahead=temp->right;
                current->right=ahead;
                ahead->left=current;
                free(temp); 
            }
        }
        if(temp->right==NULL && count==pos)
        {
            temp->left=NULL;
            current->right=NULL;
            free(temp); 
        }
    }
    if(count!=pos)
    {
        printf("\nInvalid Position!");
        return;
    }
}
void display()
{
    struct node* temp;
    temp=head;
    if(temp==NULL)
    {
        printf("\nLinked List Empty!");
        return;
    }
    else
    {
        printf("\nThe Elements in linked list are ");
        while(temp->right!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->right;
        }
        printf("%d\n",temp->data);
    }
}
void main()
{
    int ch,val;
    do
    {
        printf("\n1. Insert at first\n2. Insert at last\n3. Insert at position");
        printf("\n4. Delete at first\n5. Delete at last\n6. Delete at position");
        printf("\n7. Display \n8. Quit \n Enter your choice: ");
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
            case 3: printf("\nEnter the value you want to add: ");
                    scanf("%d",&val);
                    insert_pos(val);
                    break;
            case 4: deletef();
                    break;
            case 5: deletel();
                    break;
            case 6: delete_pos();
                    break;
            case 7: display();
                    break;
            case 8: ch=8;
                    break;
            default: printf("\nEnter a valid choice!");
                    break;
        }
    }while(ch!=8);
}