#include <iostream>
#include <string>
using namespace std;

typedef int DataType;

typedef struct _node {
    DataType data;
    struct _node *next;
}node;

void initlist(node *&head) {
    head=new node;
    head->next=nullptr;
}

int getLength(node *&head) {
    node *p;
    p=head;
    int i;
    for(i=0;p->next!=nullptr;i++) {
        p=p->next;
    }
    return i;
}

int deleteNode(node *&head,int i,DataType &x) {
    if(i<1 || i>getLength(head)) return 0;
    node *p,*r,*s;
    p=head;
    for(int j=0;j<i-1;j++) {
        p=p->next;
    }
    r=p->next;
    s=r->next;
    p->next=s;
    x=r->data;
    delete r;
    return 1;
}

int insertNode(node *&head,int i,DataType x) {
    if(i<1 || i>getLength(head)+1) return 0;
    node *p,*r,*s;
    p=head;
    for(int j=0;j<i-1;j++) {
        p=p->next;
    }
    r=p->next;
    s=new node;
    s->data=x;
    s->next=r;
    p->next=s;
    return 1;
}

int inputList(node *&head,int n) {
    node *p,*r,*s;
    p=head;
    for(int i=0;i<n;i++) {
        s=new node;
        cin>>s->data;
        p->next=s;
        p=s;
    }
    p->next=nullptr;
    return 0;
}

void displayList(node *&head) {
    node *p;
    p=head->next;
    if(p==nullptr) {
        cout<<"empty\n";
        return;
    }
    while(p!=nullptr) {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main() {
    int n;
    cin>>n;
    node *head;
    initlist(head);
    inputList(head,n);
    string op;
    while(cin>>op) {
        if(op=="ins") {
            int i;
            DataType x;
            cin>>i>>x;
            if(!insertNode(head,i,x)) cout<<"error!\n";
        }
        else if(op=="del") {
            int i;
            DataType x;
            cin>>i;
            if(!deleteNode(head,i,x)) cout<<"error!\n";
        }
        else if(op=="dis") {
            displayList(head);
        }
        else if(op=="cnt") {
            cout<<getLength(head)<<endl;;
        }
    }
}
