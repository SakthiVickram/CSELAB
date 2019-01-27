#include<stdio.h>
#include<conio.h>

struct tree
{
int data;
struct tree *left;
struct tree *right;
}*t,*l,*r,*q;

struct tree *insert(int,struct tree*);
void inorder(struct tree*);
void postorder(struct tree*);
void preorder(struct tree *);
struct tree *find(int,struct tree *);
struct tree *findmin(struct tree *);
void findmini(struct tree *);
struct tree *findmax(struct tree *);
struct tree *del(int x,struct tree *);

void main()
{
clrscr();
t=NULL;
t=insert(3,t);
t=insert(1,t);
t=insert(4,t);
t=insert(6,t);
t=insert(9,t);
t=insert(2,t);
t=insert(5,t);
t=insert(7,t);
printf("Inorder:");
inorder(t);
printf("\n");
printf("postorder:");
postorder(t);
printf("\n");
printf("preorder:");
preorder(t);
printf("\n");
l=r=q=t;
l=find(7,l);
printf("element found:%d",*l);
r=findmin(r);
//findmini(t);
printf("The minimum no is:%d\n",r->data);
q=findmax(q);
printf("The maximum no is:%d\n",q->data);
del(5,t);
getch();
}



struct tree *insert(int x,struct tree *t)
{
if(t==NULL)
{
t=(struct tree *)malloc(sizeof(struct tree));
t->data=x;
t->left=t->right=NULL;
}
if( x < t->data)
{
t->left=insert(x,t->left);
printf("goes left\n");
}
if( x > t->data)
{
t->right=insert(x,t->right);
printf("goes right\n");
}
return t;
}

void inorder(struct tree *r)
{
if(r==NULL)
return ;
inorder(r->left);
printf("%d",r->data);
inorder(r->right);
}
void postorder(struct tree *r)
{
if(r==NULL)
return ;
postorder(r->left);
postorder(r->right);
printf("%d",r->data);
}
void preorder(struct tree *r)
{
if(r==NULL)
return ;
printf("%d",r->data);
preorder(r->left);
preorder(r->right);
}

struct tree *find(int x,struct tree *t)
{
if(t==NULL)
return NULL;
if( x < t->data)
return find( x,t->left);
if( x > t->data)
return find( x,t->right);
return t;
}

struct tree *findmin(struct tree *t)
{
if(t==NULL)
return NULL;
if(t->left==NULL)
return t;
return findmin(t->left);
}
void findmini(struct tree *t)
{
while(t->left!=NULL)
{
t=t->left;
}
printf("minimum element:%d",t->data);
}
struct tree *findmax(struct tree *t)
{
if(t==NULL)
return NULL;
if(t->right==NULL)
return t;
return findmax(t->right);
}
struct tree *del(int x,struct tree *t)
{
struct tree *tmp;
if(t==NULL)
printf("element not found");
else if(x<t->data)
t->left=del(x,t->left);
else if(x>t->data)
t->right=del(x,t->right);
else if(t->left && t->right)
{
tmp=findmin(t->right);
t->data=tmp->data;
t->right=del(t->data,t->right);
}
else
{
tmp=t;
if(t->left==NULL)
t=t->right;
else if(t->right==NULL)
t=t->left;
free(tmp);
}

}