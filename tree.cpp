#include <iostream>
using namespace std;
struct node
{
char data;
node *left,*right;
};
class stack
{
node *data[30];
int top;
public:
stack()
{
top=-1;
}
int empty()
{
if(top==-1)
return 1;
return 0;
}
void push(node*p)
{
data[++top]=p;
}
node *pop()
{
return(data[top--]);
}
};
class expression
{
public:
node*create_from_post(char []);
void inorder(node *t);
void preorder(node *t);
void postorder(node *t);

};
node*expression::create_from_post(char exp[])
{
char c;
stack s;
node *top,*t1,*t2,*root;
int i;
for(i=0;exp[i]!='\0';i++)
{
c=exp[i];
if(isalnum(c))
{
top=new node;
top->left=NULL;
top->right=NULL;
top->data=c;
s.push(top);
}
else
{
t2=s.pop();

t1=s.pop();
top=new node;
top->data=c;
top->left=t1;
top->right=t2;
s.push(top);
}
}
root=s.pop();
return (root);
}
void expression::inorder(node *t)
{
if(t!=NULL)
{
inorder(t->left);
cout<<" "<<t->data;
inorder(t->right);
}
}
//     *  
//  +      - 
// 5 2    3   1
void expression::preorder(node *t)
{
if(t!=NULL)
{
cout<<" "<<t->data;//* + 5 2 - 3 1
preorder(t->left);//+ 5
preorder(t->right);
}
}
void expression::postorder(node *t)
{
if(t!=NULL)
{
postorder(t->left);
postorder(t->right);
cout<<" "<<t->data;
}
}


int main()
{
int ch;
char postfix[30];
node*root;
root=NULL;
expression e;
do
{
cout<<"=====================================================";
cout<<"\n1Enter postfix expression";
cout<<"\n2 recursive Traversal";
cout<<"\n=====================================================";
cout<<"\nEnter your choice";
cin>>ch;
cout<<"\n=====================================================";


switch(ch)
{
case 1:
cout<<"\nEnter postfix expression";
cin>>postfix;
//root=e.create_from_post(postfix);
root=e.create_from_post(postfix);
break;
case 2:
cout<<"\nPreorder Traversal";
e.preorder(root);
cout<<"\nInorder Traversal";
e.inorder(root);
cout<<"\nPostorder Traversal";
e.postorder(root);
break;
case 3:
cout<<"\n inorder Traversal";

break;
}

}while(ch==1);
}
