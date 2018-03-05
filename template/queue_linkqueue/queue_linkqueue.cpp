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

int main() {
    string op;
    linkqueue *q;
    initQueue(q);
    while(cin>>op) {
        if(op=="enqueue") {
            DataType x;
            cin>>x;
            if(!enQueue(q,x)) cout<<"queue is full\n";
        }
        else if(op=="dequeue") {
            DataType x;
            if(!deQueue(q,x)) cout<<"queue is empty\n";
        }
        else if(op=="cnt") {
            cout<<getLength(q)<<endl;
        }
        else if(op=="isempty") {
            if(isEmpty(q)) cout<<"empty\n";
            else cout<<"not empty\n";
        }
        else if(op=="print") {
            printQueue(q);
        }
    }
}
