#include <iostream>
#include <string>
using namespace std;

typedef int DataType;

typedef struct _node {
    DataType data;
    struct _node *next;
}node;

void initList(node *&head) {
    head=new node;
    head->next=head;
}

void inputList(node *&head,int n) {
    node *p,*s;
    p=head;
    for(int i=0;i<n;i++) {
        s=new node;
        cin>>s->data;
        p->next=s;
        p=s;
    }
    p->next=head;
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
    for(int j=0;j<i;j++) {
        p=p->next;
    }
    r=p->next;
    s=new node;
    s->data=x;
    p->next=s;
    s->next=r;
    return 1;
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
    x=r->data;
    p->next=s;
    delete r;
    return 1;
}

void displayList(node *&head) {
    node *p;
    p=head->next;
    for(int i=0;i<getLength(head);i++) {
        cout<<p->data<<" ";
        p=p->next;
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
        else if(op=="dis") {
            if(!getLength(head)) cout<<"empty!\n";
            else displayList(head);
        }
        else if(op=="cnt") {
            cout<<getLength(head)<<endl;;
        }
        else if(op=="dislf") {
            node *p;
            p=head;
            for(int i=0;i<getLength(head);i++) {
                p=p->next;
            }
            cout<<p->data<<" "<<head->next->data<<endl;
        }
    }
}
