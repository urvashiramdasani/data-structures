//Polynomial Addition using singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node* link;
};
struct node* head1=NULL;
struct node* head2=NULL;
struct node* head=NULL;
struct node* createNode()
{
    struct node* newnode=(struct node* ) malloc(sizeof(struct node* ));
    newnode->link=NULL;
    return newnode;
}
void inser_sort(struct node* temp_head,int e,int c)
{
    struct node* temp=temp_head;
    struct node* current=0;
    while(temp->link!=NULL && temp->expo>e)
    {
        current=temp;
        temp=temp->link;
    }
    if(current==0)
    {
        temp=createNode();
        temp->coeff = c;
        temp->expo = e;
        temp->link=temp_head;
        temp_head=temp;
    }
    else if(temp->expo==e)
    {
        temp->coeff+=c;
    }
    else if(temp->link==NULL)
    {
        temp->link=createNode();
        temp=temp->link;
        temp->link=NULL;
        temp->coeff=c;
        temp->expo=e;
    }
    else 
    {
        current->link=createNode();
        current=current->link;
        current->link=temp;
        current->expo=e;
        current->coeff=c;
    }
}
void createPolynomial(struct node** temp_head)
{
    struct node* newnode=createNode();
    printf("Enter co-efficient: ");
    scanf("%d", &newnode->coeff);
    printf("Enter exponential: ");
    scanf("%d", &newnode->expo);
    *temp_head=newnode;
    // struct node* temp_p=newnode;
    int ch = 0;
    while(1)
    {
        fflush(stdin);
        printf("Enter -1 to end: ");
        scanf("%d",&ch);
        if(ch==-1) break;
        int c;
        printf("\nEnter the Co-efficient: ");
        scanf("%d",&c);
        int e;
        printf("\nEnter the Exponent: ");
        scanf("%d",&e);
        inser_sort(*temp_head,e,c);
        fflush(stdin);
        fflush(stdout);
    }
}

void add()
{
   struct node* r=createNode();
   r->link=NULL;
   head=r;
   struct node* p1,* p2,* temp;
   p1=head1;
   p2=head2;
   if(p1==NULL && p2==NULL)
   {
       printf("\nNo Polynomials to add!");
       return;
   } 
   else
   {
       while(p1!=NULL && p2!=NULL)
       {
           if(p1->expo==p2->expo)
           {
               r->coeff=p1->coeff+p2->coeff;
               r->expo=p1->expo;
               p1=p1->link;
               p2=p2->link;
           }
           else if(p1->expo<p2->expo)
           {
               r->coeff=p2->coeff;
               r->expo=p2->expo;
               p2=p2->link;
           }
           else
           {
               r->coeff=p1->coeff;
               r->expo=p1->expo;
               p1=p1->link;
           }
            r->link=createNode();
            r=r->link;
            r->link=NULL;
       }
       if(p1==0 && p2!=0) r->link = p2;
       else if(p2==0 && p1!=0) r->link = p1;
    //    if(p1->link==NULL && p2->link!=NULL)
    //    {
    //        while(p2->link!=NULL)
    //        {
    //            r->coeff=p2->coeff;
    //            r->expo=p2->expo;
    //            p2=p2->link;
    //            r=setr(r);
    //        }
    //        r->coeff=p2->coeff;
    //        r->expo=p2->expo;
    //        r->link=NULL;
    //    }
    //    else if(p1->link!=NULL && p2->link==NULL)
    //    {
    //         while(p1->link!=NULL)
    //         {
    //             r->coeff=p1->coeff;
    //             r->expo=p1->expo;
    //             p1=p1->link;
    //             r=setr(r);
    //         }
    //         r->coeff=p1->coeff;
    //         r->expo=p1->expo;
    //         r->link=NULL;
    //    }
   }
}
void display()
{
    struct node* r=head;
    if(head==NULL)
    {
        printf("\nEmpty Polynomial!");
        return;
    }
    else
    {
        printf("\nThe resultant polynomial is ");
        while(r->link!=NULL)
        {
            printf("%dx%d + ",r->coeff,r->expo);
            r=r->link;
        }
        printf("%dx%d",r->coeff,r->expo);
    } 
}
void main()
{
    int ch;
    do
    {
        printf("\n1. Get Polynomial \n2. Add Polynomial \n3. Display \n4. Quit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nInsert first Polynomial: \n");
                    createPolynomial(&head1);
                    printf("\nInsert second Polynomial: \n");
                    createPolynomial(&head2);
                    break;
            case 2: add();
                    break;
            case 3: display();
                    break;
            case 4: ch=4;
                    break;
            default: printf("\nEnter a valid choice!");
                    break;
        }
    } while (ch!=4);
}