#include <iostream>
#include <string>
#define MAX_SIZE 5
//The queue can only have (MAX_SIZE-1) elements
using namespace std;

typedef int DataType;

typedef struct _circQueue {
    DataType data[MAX_SIZE];
    int head,rear;
}circQueue;

void initQueue(circQueue &q) {
    q.head=0;
    q.rear=0;
}

int enQueue(circQueue &q,DataType x) {
    if((q.rear+1)%MAX_SIZE==q.head) return 0;
    q.data[q.rear]=x;
    q.rear=(q.rear+1)%MAX_SIZE;
    return 1;
}

int deQueue(circQueue &q,DataType &x) {
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

void printQueue(circQueue q) {
    if(q.head==q.rear) {
        cout<<"empty\n";
        return;
    }
    if(q.head<q.rear) {
        for(int i=q.head;i<q.rear;i++) {
            cout<<q.data[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(q.head>q.rear) {
        for(int i=q.head;i<MAX_SIZE;i++) {
            cout<<q.data[i]<<" ";
        }
        for(int i=0;i<q.rear;i++) {
            cout<<q.data[i]<<" ";
        }
        cout<<endl;
        return;
    }
}

int main() {
    string op;
    circQueue q;
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
        else if(op=="isfull") {
            if(isFull(q)) cout<<"full\n";
            else cout<<"not full\n";
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

