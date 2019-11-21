//Program to add two polynomial equations
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node* link;
};
struct node* createNode()
{
    struct node* newnode=(struct node* ) malloc(sizeof(struct node));
    newnode->link=NULL;
    newnode->coeff=0;
    newnode->expo=0;
    return newnode;
}
struct node* insert(struct node* t_head,int c,int e)
{
    struct node* temp=t_head;
    struct node* current=t_head;
    if(t_head->expo<e)
    {
        temp=createNode();
        temp->link=t_head;
        temp->coeff=c;
        temp->expo=e;
        t_head=temp;
        return t_head;
    }
    else
    {
        while(temp!=NULL && temp->expo>e)
        {
            current=temp;
            temp=temp->link;
        }
        if(temp==NULL)
        {
            current->link=createNode();
            current = current->link;
            current->coeff=c;
            current->expo=e;
        }
        else if(temp->expo==e)
        {
            temp->coeff+=c;
        }
        else
        {
            current->link=createNode();
            current=current->link;
            current->link=temp;
            current->coeff=c;
            current->expo=e;
        }   
    }
    return t_head;
}
struct node* getPolynomial(struct node* temp_head)
{
    int c,e,ch;
    struct node* n=createNode();
    printf("\nEnter Exponent: ");
    scanf("%d",&(n->expo));
    printf("\nEnter Coefficient: ");
    scanf("%d",&(n->coeff));
    temp_head=n;
    while(1)
    {
        printf("\nEnter -1 to end: ");
        scanf("%d",&ch);
        if(ch==-1) break;
        printf("\nEnter Exponent: ");
        scanf("%d",&e);
        printf("\nEnter Coefficient: ");
        scanf("%d",&c);
        temp_head=insert(temp_head,c,e);
    }
    return temp_head;
}
struct node* add(struct node* temp_head1,struct node* temp_head2,struct node* head)
{
    struct node* p1=temp_head1;
    struct node* p2=temp_head2;
    struct node* r = NULL;
    while(p1!=NULL && p2!=NULL)
    {
        if(r == NULL){
            r = createNode();
            head = r;
        }
        else{
            r->link=createNode();
            r=r->link;
        }
        if(p1->expo==p2->expo)
        {
            r->coeff=p1->coeff+p2->coeff;
            r->expo=p1->expo;
            p1=p1->link;
            p2=p2->link;
        }
        else if(p1->expo>p2->expo)
        {
            r->coeff=p1->coeff;
            r->expo=p1->expo;
            p1=p1->link;
        }
        else
        {
            r->coeff=p2->coeff;
            r->expo=p2->expo;
            p2=p2->link;
        }
    }
    if(p1!=NULL && p2==NULL) r->link=p1;
    else if(p1==NULL && p2!=NULL) r->link=p2;
    return head;
}
void display(struct node* temp__head)
{
    if(temp__head==NULL)
    {
        printf("\nPolynomial Empty!");
        return;
    }
    printf("\nThe Resulatant Polynomial is ");
    struct node* temp=temp__head;
    while(temp->link!=NULL)
    {
        printf("%dx%d + ",temp->coeff,temp->expo);
        temp=temp->link;
    }
    printf("%dx%d",temp->coeff,temp->expo);
}
int main()
{
    struct node* head=NULL;
    struct node* head1=NULL;
    struct node* head2=NULL;
    int val,ch;
    do
    {
        printf("\n1. Get Polynomial \n2. Add Polynomial \n3. Display \n4. Quit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nInsert first polynomial: ");
                    head1=getPolynomial(head1);
                    display(head1);
                    printf("\nInsert second polynomial: ");
                    head2=getPolynomial(head2);
                    display(head2);
                    break;
            case 2: head=add(head1,head2,head);
                    if(head==NULL) printf("\nNo polynomials to add");
                    break;
            case 3: display(head);
                    break;
            case 4: ch=4;
                    break;
            default: printf("\nInvalid Choice!");
                    break;
        }
    } while (ch!=4); 
}