#include <iostream>
#include <string>
using namespace std;
//link queue->head pointer->pointer with data
typedef int DataType;

typedef struct _node {
    DataType data;
    struct _node *next;
}node;

typedef struct _linkqueue {
    node *head,*rear;
}linkqueue;

void initQueue(linkqueue *&q) {
    q=new linkqueue;
    node *p=new node;
    q->head=p;
    q->rear=p;
    p->next=nullptr;
}

int getLength(linkqueue *&q) {
    node *p;
    p=q->head->next;
    int i;
    for(i=0;p!=nullptr;i++) {
        p=p->next;
    }
    return i;
}

int enQueue(linkqueue *&q,DataType x) {
    node *p=new node;
    p->data=x;
    p->next=nullptr;
    q->rear->next=p;
    q->rear=p;
    return 1;
}

int deQueue(linkqueue *&q,DataType &x) {
    if(q->head->next==nullptr) return 0;
    node *p,*r;
    p=q->head->next;
    r=p->next;
    x=p->data;
    q->head->next=r;
    delete p;
    return 1;
}

int isEmpty(linkqueue *&q) {
    if(getLength(q)==0) return 1;
    return 0;
}

void printQueue(linkqueue *&q) {
    node *p;
    p=q->head->next;
    if(p==nullptr) {
        cout<<"empty\n";
        return;
    }
    while(p!=nullptr) {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
    return;
}

void yangvi(int n) {
    linkqueue *q;
    initQueue(q);
    enQueue(q,0);
    enQueue(q,1);
    int i,j;
    DataType s=0,t;
    for(int i=1;i<=n;i++) {
        if(i!=1) cout<<endl;
        enQueue(q,0);
        for(int j=1;j<=i+2;j++) {
            deQueue(q,t);
            enQueue(q,s+t);
            s=t;
            if(s!=0) cout<<s<<" ";
        }
    }
}

int main() {
    int n;
    while(cin>>n) {
        yangvi(n);
        cout<<endl;
    }
}

