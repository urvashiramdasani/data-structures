#include<stdio.h>
#include<string.h>
struct stack
{
    int top;
    int size;
    char stk[100][100];
};
void push(struct stack *s,char post[])
{
    if(s->top==s->size-1)
    {
        printf("\nStack Overflow!");
        return;
    }
    else
    {
        s->top++;
        strcpy(s->stk[s->top],post);
    }
    
}
void pop(struct stack *s,char var[])
{
    if(s->top==-1)
    {
        printf("\nStack Underflow!");
        return;
    }
    else
    {
        strcpy(var,s->stk[s->top]);
        strcpy(s->stk[s->top],"");
        s->top--;
    }
}
void display(struct stack *s)
{
    printf("\nYour infix expression is ");
    for(int i=0;i<s->size;i++)
    {
        printf("%s",s->stk[i]);
    }
}
void main()
{
    struct stack s;
    char var1[100]="NULL";
    char var2[100]="NULL";
    char post[100][100];
    int i;
    s.top=-1;
    printf("\nEnter the size of stack: ");
    scanf("%d",&s.size);
    for(i=0;i<s.size;i++)
    {
        printf("\nEnter your character: ");
        scanf("%s",post[i]); 
    }
    for(i=0;i<s.size;i++)
    {
        if(strcmp(post[i],"+")==0 || strcmp(post[i],"-")==0 || strcmp(post[i],"*")==0 || strcmp(post[i],"/")==0 || strcmp(post[i],"^")==0)
        {
            pop(&s,var1);
            pop(&s,var2);
            strcat(var2,post[i]);
            strcat(var2,var1);
            push(&s,var2);            
        }
        push(&s,post[i]);
    }
        printf("\nYour Postfix expression was ");
        printf("%s",post[0]);
        printf("\nYour infix expression is ");
        printf("%s",s.stk[0]);
        //display(&s);
}