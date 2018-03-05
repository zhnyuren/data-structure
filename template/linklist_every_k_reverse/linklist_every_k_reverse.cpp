#include <iostream>
#include <stdio.h>
using namespace std;
struct node {
    int data;
    node* next;
};
int main() {
    int k;
    cin>>k;
    node *L,*p,*q,*r,*s;
    L=new node;
    p=L;
    int x;
    while(~scanf("%d",&x)) {
        s=new node;
        s->data=x;
        p->next=s;
        p=s;
    }p->next=NULL;
    node *last=L;
    q=L->next;
    node *pre,*right;
    int cntr =0;
    int len =0;
    while(q!=NULL) {
        len++;
        q=q->next;
    }
    int n=len;
    q=L->next;
    len=len/k;
    while(q!=NULL && cntr<len) {
        pre=NULL;
        right=NULL;
        s=q;
        int i=0;
        while(q!=NULL && i<k) {
            right=q->next;
            q->next=pre;
            pre=q;
            q=right;
            i++;
        }
        last->next=pre;
        last=s;
        cntr++;
        s->next=q;
    }
    p=L->next;
    for(int i=0;i<n;i++) {
        cout<<p->data<<" ";
        p=p->next;
    }
}
