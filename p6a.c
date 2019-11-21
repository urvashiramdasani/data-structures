//Program to implement binary search tree
#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree* right;
    struct tree* left;
};
struct tree* createNode()
{
    struct tree* newnode=(struct tree* ) malloc(sizeof(struct tree));
    newnode->data=0;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void insert(struct tree* root,int val)
{
    if(val==root->data)
    {
        printf("\nInvalid data");
        return;
    }
    else if(val>root->data)
    {
        if(root->right==NULL)
        {
            root->right = createNode();
            root->right->data = val;
            return;
        }
        insert(root->right,val);
    }
    else 
    {
        if(root->left==NULL)
        {
            root->left = createNode();
            root->left->data = val;
            return;
        }
        insert(root->left,val);
    }
}
void preorder(struct tree* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        printf("\t%d",root->data);
        preorder(root->left);
        preorder(root->right);  
    }
}
void inorder(struct tree* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        struct tree* p=root;
        inorder(p->left);
        printf("\t%d",p->data);
        inorder(p->right);
    }
}
void postorder(struct tree* root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        struct tree* p=root;
        postorder(p->left);
        postorder(p->right);
        printf("\t%d",p->data);
    }
}
struct tree* findmin(struct tree* p)
{
    while(p->left!=NULL)
    {
        p=p->left;
    }
    return p;
}
struct tree* delete(struct tree* p,int val)
{
    if(val>p->data && (p->left!=NULL || p->right!=NULL))
    {
        p->right=delete(p->right,val);
        return p;
    }
    else if(val<p->data && (p->left!=NULL || p->right!=NULL))
    {
        p->left=delete(p->left,val);
        return p;
    }
    struct tree* temp=p;
    if(p->data==val)
    {
        if(p->left==NULL && p->right==NULL)
            return NULL;
        else if(p->left==NULL)
        {
            p=p->right;
            return p;
        }
        else if(p->right==NULL)
        {
            p=p->left;
            return p;
        }
        else
        {
            temp=findmin(p->right);
            p->data=temp->data;
            p->right=delete(p->right,temp->data);
            return p;
        }
    }
    else
    {
        printf("\nValue not Found!");
    }
}
void main()
{
    struct tree* root=NULL;
    int ch,val;
    do
    {
        printf("\n1. Insert \n2. Preorder Traversal \n3. Inorder Traversal \n4. Postorder Traversal");
        printf("\n5. Delete \n6. Quit \nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nInsert the value: ");
                    scanf("%d",&val);
                    if(root != NULL) insert(root,val);
                    else{ root = createNode();root->data = val;}
                    break;
            case 2: preorder(root);
                    break;
            case 3: inorder(root);
                    break;
            case 4: postorder(root);
                    break;
            case 5: if(root==NULL) printf("\nTree Empty!");
                    else
                    {
                        printf("\nEnter the value you want to delete: ");
                        scanf("%d",&val);
                        root=delete(root,val);
                    }
                    break;
            case 6: ch=6;
                    break;
            default: printf("\nInvalid Choice!");
                    break;
        }
    } while (ch!=6);
}