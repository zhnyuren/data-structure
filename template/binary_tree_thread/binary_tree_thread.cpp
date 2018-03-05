#include <iostream>
using namespace std;

typedef char TDataType;

typedef struct node {
    TDataType data;
    int ltag,rtag;
    struct node *lchild,*rchild;
}THRDnode;

void createBinTreePre(THRDnode *&root) {
    TDataType item;
    cin>>item;
    if(item==';') return;
    if(item!='#') {
        root=new node;
        root->data=item;
        root->ltag=0;
        root->rtag=0;
        createBinTreePre(root->lchild);
        createBinTreePre(root->rchild);
    }
    else root=nullptr;
}

void InOrderThreaded(THRDnode *p,THRDnode *&pre) {
    if(p!=nullptr) {
        InOrderThreaded(p->lchild,pre);
        if(p->lchild==nullptr) {
            p->lchild=pre;
            p->ltag=1;
        }
        if(pre!=nullptr && pre->rchild==nullptr) {
            pre->rchild=p;
            pre->rtag=1;
        }
        pre=p;
        InOrderThreaded(p->rchild,pre);
    }
}

void createInThread(THRDnode *root) {
    THRDnode *pre=nullptr;
    if(root!=nullptr) {
        InOrderThreaded(root,pre);
        pre->rchild=nullptr;
        pre->rtag=1;
    }
}

THRDnode* findInFirst(THRDnode *p) {
    while(p->ltag==0) p=p->lchild;
    return p;
}

THRDnode* findInLast(THRDnode *p) {
    while(p->rtag==0) p=p->rchild;
    return p;
}

THRDnode* findInNext(THRDnode *p) {
    if(p->rtag==0) return findInFirst(p->rchild);
    else return p->rchild;
}

THRDnode* findInPre(THRDnode *p) {
    if(p->ltag==0) return findInFirst(p->lchild);
    else return p->lchild;
}

void InOrder(THRDnode *root) {
    for(THRDnode *p=findInFirst(root);p!=nullptr;p=findInNext(p)) {
        cout<<p->data<<" ";
    }
    cout<<endl;
}

int main() {
    THRDnode* root;
    createBinTreePre(root);
    createInThread(root);
    InOrder(root);
}

