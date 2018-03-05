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
    int tmp=m;
    for(int i=0;i<n-1;i++) {
        tmp=m%(n-i);
        if(tmp==0) tmp=n-i;
        if(tmp==1) tmp=n-i+1;
        for(int j=1;j<tmp;j++) {
            pre=p;
            p=p->next;
        }
        s=p->next;
        cout<<p->data<<" ";
        delete p;
        pre->next=s;
        p=s;
    }
    cout<<endl;
    cout<<p->data<<endl;
}

