#include <iostream>
#include <string>
using namespace std;

typedef int DataType;

typedef struct _node {
    DataType data;
    struct _node *next;
}node;

typedef struct _linkDQueue {
    node *head,*rear;
}linkDQueue;

void initQueue(linkDQueue *&q) {
    q=new linkDQueue;
    node *p=new node;
    q->head=p;
    q->rear=p;
    p->next=nullptr;
}

int enQueueRear(linkDQueue *&q,DataType x) {
    node *p=new node;
    p->data=x;
    p->next=nullptr;
    q->rear->next=p;
    q->rear=p;
    return 1;
}

int deQueueHead(linkDQueue *&q,DataType &x) {
    if(q->head->next==nullptr) return 0;
    node *p,*r;
    p=q->head->next;
    r=p->next;
    x=p->data;
    q->head->next=r;
    delete p;
    return 1;
}

int enQueueHead(linkDQueue *&q,DataType x) {
    node *p=new node;
    p->data=x;
    p->next=q->head->next;
    q->head->next=p;
    return 1;
}

int deQueueRear(linkDQueue *&q,DataType &x) {
    if(q->head->next==nullptr) return 0;
    node *p,*r;
    r=q->head;
    while(r->next!=q->rear) r=r->next;
    p=q->rear;
    r->next=nullptr;
    q->rear=r;
    x=p->data;
    delete p;
    return 1;
}

int getLength(linkDQueue *q) {
    node *p;
    p=q->head;
    int i;
    for(i=0;p->next!=nullptr;i++) {
        p=p->next;
    }
    return i;
}

void printQueue(linkDQueue *q) {
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

int isEmpty(linkDQueue *q) {
    if(q->head->next==nullptr) return 1;
    return 0;
}

int main() {
    string op;
    linkDQueue *q;
    initQueue(q);
    while(cin>>op) {
        if(op=="enqueuehead") {
            DataType x;
            cin>>x;
            if(!enQueueHead(q,x)) cout<<"queue is full\n";
        }
        else if(op=="enqueuerear") {
            DataType x;
            cin>>x;
            if(!enQueueRear(q,x)) cout<<"queue is full\n";
        }
        else if(op=="dequeuehead") {
            DataType x;
            if(!deQueueHead(q,x)) cout<<"queue is empty\n";
        }
        else if(op=="dequeuerear") {
            DataType x;
            if(!deQueueRear(q,x)) cout<<"queue is empty\n";
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
