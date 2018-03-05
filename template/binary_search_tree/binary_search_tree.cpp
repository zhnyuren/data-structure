#include <iostream>
#include <cstdio>
using namespace std;

typedef int BSTDataType;

typedef struct node {
    BSTDataType data;
    struct node *lchild,*rchild;
}BSTnode,*BSTtree;

BSTnode* searchBST(BSTnode *root,BSTDataType x,BSTnode *&father) {
    BSTnode *p=root;
    father=nullptr;
    while(p!=nullptr && p->data!=x) {
        father=p;
        if(x>p->data) p=p->rchild;
        else p=p->lchild;
    }
    return p;
}

int insertBST(BSTnode *&root,BSTDataType x) {
    BSTnode *s,*p,*f;
    p=searchBST(root,x,f);
    if(p!=nullptr) return 0;
    s=new BSTnode;
    s->data=x;
    s->lchild=nullptr;
    s->rchild=nullptr;
    if(f==nullptr) root=s;
    else if(x>f->data) f->rchild=s;
    else f->lchild=s;
    return 1;
}

int removeBST(BSTnode *&root,BSTDataType x) {
    BSTnode *s,*p,*f;
    p=searchBST(root,x,f);
    if(p==nullptr) return 0;
    if(p==root && p->lchild==nullptr && p->rchild==nullptr) {//only root left
        root=nullptr;
        return 1;
    }
    if(p->lchild==nullptr && p->rchild==nullptr) {//leaf
        if(p==f->lchild) f->lchild=nullptr;
        else f->rchild=nullptr;
        delete p;
        return 1;
    }
    if(p->lchild!=nullptr && p->rchild!=nullptr) {
        s=p->lchild;
        while(s->rchild!=nullptr) {
            f=s;
            s=s->rchild;
        }
        p->data=s->data;
        p=s;
    }

    if(p->lchild!=nullptr) s=p->lchild;
    else s=p->rchild;

    if(p==root) root=s;
    else if(s->data<f->data) f->lchild=s;
    else f->rchild=s;

    delete p;
    return 1;
}

int removeBook(BSTnode *&root,BSTDataType x) {
    BSTnode *s,*p,*f;
    p=searchBST(root,x,f);
    if(p==NULL) return 0;
    if(p->lchild!=NULL p->rchild!=NULL) {
        s=p->lchild;
        while(s->rchild!=NULL) {
            f=s;
            s=s->rchild;
        }
        p->data=s->data;
        p=s;
        if(p->lchild!=NULL) s=p->lchild;
        else s=p->rchild;
        if(p==root) root=s;
        else if(s->data<f->data) f->lchild=s;
        else f->rchild=s;
        delete p;
        return 1;
    }
}

void createBST(BSTnode *&root) {
    BSTDataType item;
    root=nullptr;
    while(cin>>item) {
        insertBST(root,item);
        char c=getchar();
        if(c=='\n') break;
    }
}

void PreOrder(BSTnode *root) {
    if(root!=nullptr) {
        cout<<root->data<<" ";
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

int main() {
    while(1) {
        BSTnode *root;
        createBST(root);
        BSTDataType x;
        cin>>x;
        removeBST(root,x);
        PreOrder(root);
        cout<<endl;
    }
}
