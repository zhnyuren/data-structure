#include <iostream>
#include <string>
#define MAX_SIZE 5
using namespace std;

typedef int DataType;

typedef struct _sqDQueue {
    DataType data[MAX_SIZE];
    int head,rear;
}sqDQueue;

void initQueue(sqDQueue &q) {
    q.head=0;
    q.rear=0;
}

int getLength(sqDQueue q) {
    return (q.rear+MAX_SIZE-q.head)%MAX_SIZE;
}

int enQueueRear(sqDQueue &q,DataType x) {
    if((q.rear+1)%MAX_SIZE==q.head) return 0;
    q.data[q.rear]=x;
    q.rear=(q.rear+1)%MAX_SIZE;
    return 1;
}

int deQueueHead(sqDQueue &q,DataType &x) {
    if(q.rear==q.head) return 0;
    x=q.data[q.head];
    q.head=(q.head+1)%MAX_SIZE;
    return 1;
}

int enQueueHead(sqDQueue &q,DataType x) {
    if((q.rear+1)%MAX_SIZE==q.head) return 0;
    q.head=(q.head+MAX_SIZE-1)%MAX_SIZE;
    q.data[q.head]=x;
    return 1;
}

int deQueueRear(sqDQueue &q,DataType &x) {
    if(q.head==q.rear) return 0;
    q.rear=(q.rear-1+MAX_SIZE)%MAX_SIZE;
    x=q.data[q.rear];
    return 1;
}

void printQueue(sqDQueue q) {
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

int isFull(sqDQueue q) {
    if((q.rear+1)%MAX_SIZE==q.head) return 1;
    return 0;
}

int isEmpty(sqDQueue q) {
    if(q.rear==q.head) return 1;
    return 0;
}

int main() {
    string op;
    sqDQueue q;
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
