#include <iostream>
using namespace std;

typedef int DataType;

typedef struct _node {
    DataType data;
    struct _node *next;
}node;

int main() {
    int n,m;
    cin>>n>>m;
    node *head=new node;
    node *p,*pre,*s;
    p=head;
    for(int i=0;i<n;i++) {
        s=new node;
        s->data=i+1;
        p->next=s;
        p=s;
    }
    p->next=head->next;
    p=head->next;
    for(int i=0;i<n-1;i++) {
        for(int j=1;j<m;j++) {
            pre=p;
            p=p->next;
        }
        s=p->next;
        cout<<p->data<<" ";
        delete p;
        if(m!=1) pre->next=s;
        p=s;
    }
    cout<<endl;
    cout<<p->data<<endl;
}
