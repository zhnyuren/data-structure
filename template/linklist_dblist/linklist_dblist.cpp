#include <iostream>
#include <string>
using namespace std;

typedef int DataType;

typedef struct _node {
    DataType data;
    struct _node *pre;
    struct _node *next;
}node;

void initList(node *&head) {
    head=new node;
    head->pre=head;
    head->next=head;
}

void inputList(node *&head,int n) {
    node *p,*r,*s;
    p=head;
    //pay attention to "n=0"
    if(n==0) return;
    for(int i=0;i<n;i++) {
        s=new node;
        cin>>s->data;
        p->next=s;
        s->pre=p;
        p=s;
    }
    head->pre=s;
    s->next=head;
}

int getLength(node *&head) {
    node *p;
    p=head->next;
    int i;
    for(i=0;p!=head;i++) {
        p=p->next;
    }
    return i;
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
    p->next=s;
    s->pre=p;
    s->next=r;
    r->pre=s;
    return 1;
}

int deleteNode(node *&head,int i,DataType &x) {
    if(i<1 || i>getLength(head)) return 0;
    //pay attention to "delete 1"
    node *p,*r,*s;
    if(i==1) {
        p=head->next;
        r=p->next;
        head->next=r;
        r->pre=head;
        x=p->data;
        delete p;
        return 1;
    }
    p=head;
    for(int j=0;j<i-1;j++) {
        p=p->next;
    }
    r=p->next;
    s=r->next;
    x=r->data;
    p->next=s;
    s->pre=p;
    delete r;
    return 1;
}

void dislr(node *&head) {
    node *p;
    p=head->next;
    if(p==head) {
        cout<<"empty\n";
        return;
    }
    for(int i=0;i<getLength(head);i++) {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void disrl(node *&head) {
    node *p;
    p=head->pre;
    if(p==head) {
        cout<<"empty\n";
        return;
    }
    for(int i=0;i<getLength(head);i++) {
        cout<<p->data<<" ";
        p=p->pre;
    }
    cout<<endl;
}

int main() {
    int n;
    cin>>n;
    node *head;
    initList(head);
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
        else if(op=="dislr") {
            dislr(head);
        }
        else if(op=="disrl") {
            disrl(head);
        }
        else if(op=="cnt") {
            cout<<getLength(head)<<endl;;
        }
    }
}
