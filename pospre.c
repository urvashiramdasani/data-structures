#include<string.h>
#include<stdio.h>
struct stack
{
    int top;
    int size;
    char stk[100][100];
}
void main()
{
    struct stack s;
    char infix[100][100],ch1,ch2;
    s.top=-1;
    printf("\nEnter the size of stack: ");
    scanf("%d",s.size);
    printf("\nEnter the postfix expression: ");
    for(int i=0;i<s.size;i++)
    {
        scanf("%s",infix[i]);
    }
    for(int i=0;i<strlen(infix);i++)
    {
        if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^')
        {
            int j=0;
            char res[100];
            ch1=pop(&s);
            ch2=pop(&s);
            res[j++]=infix[i];
            res[j++]=ch2;
            res[j++]=ch1;
            push(&s,res);
        }
        push(&s,res);
    }

}