#include<stdlib.h>
#include<stdio.h>
int count=0;
struct queue
{
    int front;
    int size;
    int rear;
    int arr[100];
    int p[100];
};
int prior(int n)
{
    if(n>=1 && n<=10) return 5;
    else if(n>=11 && n<=20) return 3;
    else if(n>=21 && n<=30) return 2;
    else if(n>=31 && n<=40) return 4;
    else if(n>=41 && n<=50) return 1;
    else return 0;
}
int delete(struct queue *q)
{
    int ele;
    if(q->front==-1)
    {
        printf("\nUnderflow!");
        exit(1);
    }
    else
    {
        ele=q->arr[q->front];
        if(q->front==q->rear)
            q->front=q->rear=-1;
        else
        {
            q->front+=1;
        }
        return ele;
    }
}
void display(struct queue *q)
{
    if(q->front==-1)
        printf("\nEmpty!");
    else
    {
        printf("\nThe elements in priority queue are ");
        for(int i=q->front;i<=q->rear;i++)
        {
            printf("\t%d",q->arr[i]);
        }
    }
}
void insert_sort(struct queue *q)
{
    int temp,d;
    if(q->rear==q->size-1)
    {
        printf("\nOverflow!");
        exit(1);
    }
    else
    {
        printf("\nEnter an element in queue: ");
        scanf("%d",&q->arr[count]);
        q->p[count]=prior(q->arr[count]);
        q->rear=q->rear+1; 
        if(q->front==-1) q->front=0;
    }
    count++;
    for(int i=1;i<count;i++)
    {
        d=i;
        while(d>0 && q->p[d]<q->p[d-1])
        {
            temp=q->arr[d];
            q->arr[d]=q->arr[d-1];
            q->arr[d-1]=temp;
            temp=q->p[d];
            q->p[d]=q->p[d-1];
            q->p[d-1]=temp;
            d--;
        }
    } 
}
void main()
{
    struct queue q;
    q.front=-1;
    q.rear=-1;
    int ch;
    printf("\nEnter the size of queue: ");
    scanf("%d",&q.size);
    do
    {
        printf("\n1. Insert \n2. Delete \n3. Display \n4. Quit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 2: printf("\nDeleted element is %d",delete(&q));
                    break;
            case 3: display(&q);
                    break;
            case 4: ch=4;
                    break;
            case 1: insert_sort(&q);
                    break;
            default: printf("\nEnter a valid choice!");
                        break;
        }
    } while (ch!=4);
}