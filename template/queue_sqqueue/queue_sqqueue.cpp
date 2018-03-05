#include <iostream>
#include <string>
#define MAX_SIZE 100
using namespace std;

typedef int DataType;

typedef struct _sqQueue {
    DataType data[MAX_SIZE];
    int head,rear;
}sqQueue;

void initQueue(sqQueue &q) {
    q.head=0;
    q.rear=0;
}

int enQueue(sqQueue &q,DataType x) {
    if(q.rear==MAX_SIZE) return 0;
    q.data[q.rear++]=x;
    return 1;
}

int deQueue(sqQueue &q,DataType &x) {
    if(q.rear==q.head) return 0;
    x=q.data[q.head++];
    return 1;
}

int getLength(sqQueue q) {
    return q.rear-q.head;
}

void displayQueue(sqQueue q) {
    if(getLength(q)==0) {
        cout<<"empty\n";
        return;
    }
    for(int i=q.head;i<q.rear;i++) {
        cout<<q.data[i]<<" ";
    }
    cout<<endl;
}

int main() {
    string op;
    sqQueue q;
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
        else if(op=="dis") {
            displayQueue(q);
        }
    }
}
