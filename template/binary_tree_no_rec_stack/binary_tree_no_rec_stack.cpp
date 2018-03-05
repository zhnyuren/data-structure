#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAX_SIZE 100
using namespace std;

//abc##de#g##f###

typedef char TDataType;

typedef struct node {
    TDataType data;
    struct node *lchild,*rchild;
}BTnode;

typedef BTnode* SDataType;

typedef struct _sqstack {
    SDataType data[MAX_SIZE];
    int top;
}sqstack;

void initStack(sqstack &s) {
    s.top=-1;
}

int push(sqstack &s,SDataType x) {
    if(s.top==MAX_SIZE-1) return 0;
    s.data[++s.top]=x;
    return 1;
}

int pop(sqstack &s,SDataType &x) {
    if(s.top==-1) return 0;
    x=s.data[s.top--];
    return 1;
}

int getLength(sqstack s) {
    return s.top+1;
}

int getTop(sqstack s,SDataType &x) {
    if(s.top==-1) return 0;
    x=s.data[s.top];
    return 1;
}

int isEmpty(sqstack s) {
    if(s.top==-1) return 1;
    else return 0;
}

int isFull(sqstack s) {
    if(s.top==MAX_SIZE) return 1;
    else return 0;
}

void createBinTreePre(BTnode *&root) {
    TDataType item;
    cin>>item;
    if(item==';') return;
    if(item!='#') {
        root=new BTnode;
        root->data=item;
        createBinTreePre(root->lchild);
        createBinTreePre(root->rchild);
    }
    else root=nullptr;
}

void PreOrderStack(BTnode *root) {
    sqstack S;
    initStack(S);
    BTnode *p=root;
    do {
        while(p!=nullptr) {
            cout<<p->data;
            push(S,p);
            p=p->lchild;
        }
        if(!isEmpty(S)) {
            pop(S,p);
            p=p->rchild;
        }
    } while(p!=nullptr || !isEmpty(S));
}

void InOrderStack(BTnode *root) {
    sqstack S;
    initStack(S);
    BTnode *p=root;
    do {
        while(p!=nullptr) {
            push(S,p);
            p=p->lchild;
        }
        if(!isEmpty(S)) {
            pop(S,p);
            cout<<p->data;
            p=p->rchild;
        }
    } while(p!=nullptr || !isEmpty(S));
}

void PostOrderStack(BTnode *root) {
    sqstack S;
    initStack(S);
    BTnode *p=root,*q=nullptr;
    do {
        while(p!=nullptr) {
            push(S,p);
            p=p->lchild;

        }
        if(!isEmpty(S)) {
            getTop(S,p);
            if(p->rchild!=nullptr && p->rchild!=q) p=p->rchild;
            else {
                cout<<p->data;
                pop(S,q);
                p=nullptr;
            }
        }
    } while(p!=nullptr || !isEmpty(S));
}

BTnode* findParent(BTnode *root,BTnode *p) {
    if(root==p) return nullptr;
    sqstack S;
    initStack(S);
    push(S,root);
    BTnode *r;
    while(!isEmpty(S)) {
        pop(S,r);
        if(r->lchild==p || r->rchild==p) return r;
        if(r->rchild!=nullptr) push(S,r->rchild);
        if(r->lchild!=nullptr) push(S,r->lchild);
    }
    return nullptr;
}

void testPreOrder(BTnode *root) {
    if(root==nullptr) return;
    sqstack S;
    initStack(S);
    push(S,root);
    BTnode *r;
    while(!isEmpty(S)) {
        pop(S,r);
        cout<<r->data;
        if(r->rchild!=nullptr) push(S,r->rchild);
        if(r->lchild!=nullptr) push(S,r->lchild);
    }
}

void createWithGList(BTnode *&root) {
    sqstack S;
    initStack(S);
    BTnode *p,*r;
    int flag;
    char item;
    while(1) {
        item=getchar();
//        if(item==EOF) exit(0);
        if(item=='\n') break;
        switch(item) {
        case '(':
            push(S,p);
            flag=1;
            break;
        case ',':
            flag=2;
            break;
        case ')':
            pop(S,r);
            break;
        default:
            p=new BTnode;
            p->data=item;
            p->lchild=nullptr;
            p->rchild=nullptr;
            if(root==nullptr) root=p;
            else {
                getTop(S,r);
                if(flag==1) r->lchild=p;
                else r->rchild=p;
            }
        }
    }
}

int main() {
    BTnode *root;
    createBinTreePre(root);

    PreOrderStack(root);
    cout<<endl;

    InOrderStack(root);
    cout<<endl;

    PostOrderStack(root);
    cout<<endl;

    testPreOrder(root);
    cout<<endl;

    BTnode *p=root->lchild->rchild->lchild;
    cout<<findParent(root,p)->data<<endl;

    BTnode *root1=nullptr;
    createWithGList(root1);
    PreOrderStack(root1);
    cout<<endl;
}
