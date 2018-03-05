#include <iostream>
#define MAX_SIZE 100
using namespace std;

typedef char TDataType;

typedef struct node {
    TDataType data;
    struct node *lchild,*rchild;
}BTnode, *BinTree;

void createBinTree(BTnode *&root) {
    TDataType item;
    cin>>item;
    if(item==';') return;
    if(item!='#') {
        root=new BTnode;
        root->data=item;
        createBinTree(root->lchild);
        createBinTree(root->rchild);
    }
    else root=nullptr;
}

typedef BTnode* QDataType;

typedef struct _circQueue {
    QDataType data[MAX_SIZE];
    int head,rear;
}circQueue;

void initQueue(circQueue &q) {
    q.head=0;
    q.rear=0;
}

int enQueue(circQueue &q,QDataType x) {
    if((q.rear+1)%MAX_SIZE==q.head) return 0;
    q.data[q.rear]=x;
    q.rear=(q.rear+1)%MAX_SIZE;
    return 1;
}

int deQueue(circQueue &q,QDataType &x) {
    if(q.head==q.rear) return 0;
    x=q.data[q.head];
    q.head=(q.head+1)%MAX_SIZE;
    return 1;
}

int getLength(circQueue q) {
    return (q.rear+MAX_SIZE-q.head)%MAX_SIZE;
}

int isFull(circQueue q) {
    if((q.rear+1)%MAX_SIZE==q.head) return 1;
    return 0;
}

int isEmpty(circQueue q) {
    if(q.head==q.rear) return 1;
    return 0;
}

void traversalByLevel(BTnode *root) {
    circQueue q;
    initQueue(q);
    BTnode *p=root;
    enQueue(q,p);
    while(q.head!=q.rear){
        deQueue(q,p);
        cout<<p->data;
        if(p->lchild!=nullptr) {
            enQueue(q,p->lchild);
        }
        if(p->rchild!=nullptr) {
            enQueue(q,p->rchild);
        }
    }
}

int main() {
    BTnode *root;
    createBinTree(root);
    traversalByLevel(root);
}
