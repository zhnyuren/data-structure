#include <iostream>
#include <string>
using namespace std;

typedef int DataType;

typedef struct _node {
    DataType data;
    struct _node *next;
}node;

void initStack(node *&head) {
    head->next=nullptr;
}

int push(node *&head,DataType x) {
    node *p,*s;
    p=head->next;
    s=new node;
    s->data=x;
    head->next=s;
    s->next=p;
    return 1;
}

int pop(node *&head,DataType &x) {
    if(head->next==nullptr) return 0;
    node *p,*r;
    p=head->next;
    r=p->next;
    head->next=r;
    x=p->data;
    delete p;
    return 1;
}

int getLength(node *&head) {
    node *p;
    int i;
    p=head;
    for(i=0;p->next!=nullptr;i++) {
        p=p->next;
    }
    return i;
}

int getTop(node *&head,DataType &x) {
    if(head->next==nullptr) return 0;
    x=head->next->data;
    return 1;
}

int main() {
    string op;
    node *head=new node;
    initStack(head);
    while(cin>>op) {
        if(op=="push") {
            DataType x;
            cin>>x;
            if(!push(head,x)) cout<<"stack is full\n";
        }
        else if(op=="pop") {
            DataType x;
            if(!pop(head,x)) cout<<"stack is empty\n";
            else cout<<"pop "<<x<<endl;
        }
        else if(op=="cnt") {
            cout<<getLength(head)<<endl;
        }
        else if(op=="gettop") {
            DataType x;
            if(!getTop(head,x)) cout<<"stack is empty\n";
            else cout<<x<<endl;
        }
    }
}
