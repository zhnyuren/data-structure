//consider the situation of "del 1", "ins 1 x" and "getLenth" (when only 0 or1 element in the list)
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
    head->next=nullptr;
}

int getLength(node *&head) {
    node *p;
    p=head->next;
    if(p==nullptr) return 0;
    if(p->next==p) return 1;
    int i;
    p=p->next;
    for(i=1;p!=head->next;i++) {
        p=p->next;
    }
    return i;
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

void inputList(node *&head,int n) {
    node *p,*s;
    p=head;
    for(int i=0;i<n;i++) {
        s=new node;
        cin>>s->data;
        p->next=s;
        p=s;
    }
    p->next=head->next;
}

int deleteNode(node *&head,int i,DataType &x) {
    if(i<1 || i>getLength(head)) return 0;
    node *p,*r,*s;
    if(i==1 && getLength(head)==1) {
        p=head->next;
        x=p->data;
        head->next=nullptr;
        delete p;
        return 1;
    }
    if(i==1) {
        p=head->next;
        r=p->next;
        s=p;
        while(s->next!=p) s=s->next;
        s->next=r;
        head->next=r;
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
    p->next=s;
    x=r->data;
    delete r;
    return 1;
}

int insertNode(node *&head,int i,DataType x) {
    if(i<1 || i>getLength(head)+1) return 0;
    node *p,*r,*s;
    if(i==1 && getLength(head)==0) {
        s=new node;
        s->data=x;
        head->next=s;
        s->next=s;
        return 1;
    }
    if(i==1) {
        p=head->next;
        r=p;
        while(r->next!=p) r=r->next;
        s=new node;
        s->data=x;
        head->next=s;
        r->next=s;
        s->next=p;
        return 1;
    }
    p=head;
    for(int j=0;j<i-1;j++) {
        p=p->next;
    }
    r=p->next;
    s=new node;
    s->data=x;
    p->next=s;
    s->next=r;
    return 1;
}



int main() {
    int n;
    cin>>n;
    node *head;
    initList(head);
    if(n!=0) inputList(head,n);
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
            cout<<p->data<<" "<<p->next->data<<endl;
        }
    }
}
