#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
struct node
{
    char value;
    node *left;
    node *right;
};
node* createnode(node *p,char c);
void inorder(node *p);
void preorder(node *p);
void postorder(node *p);

int main()
{
    node *p=NULL; // p is root
    string s="5372468";
    for(int i=0; i<s.length(); i++)
    {
        p=createnode(p,s[i]);
    }
    cout << "inorder  :";
    inorder(p);
    cout << endl;
    cout << "preorder :";
    preorder(p);
    cout << endl;
    cout << "postorder:";
    postorder(p);
    cout << endl;
    return 0;
}

node* createnode(node *p,char c)
{
    node *current;
    node *parent;

    // 新節點
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->value=c;
    newnode->left=NULL;
    newnode->right=NULL;
    if(p==NULL)  // first time , create root
    {
        return newnode;
    }
    else
    {
        current=p;
        while(current!=NULL)  //一直往下找
        {
            parent=current; //保留父節點
            if(parent->value > c)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        //if(parent->value > c)
        if(parent->left==NULL)
        {
            parent->left=newnode;
            //cout<<"I'm left node:"<<newnode->value<<endl;
        }
        else
        {
            parent->right=newnode;
            //cout<<"I'm right node:"<<newnode->value<<endl;
        }
    }
    return p; // return root pointer
}

void inorder(node *p)  //LVR
{
    if(p!=NULL)
    {
        inorder(p->left);
        cout<<p->value;
        inorder(p->right);
    }
}

void preorder(node *p)  //VLR
{
    if(p!=NULL)
    {
        cout<<p->value;
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(node *p)  //LRV
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->value;
    }
}
