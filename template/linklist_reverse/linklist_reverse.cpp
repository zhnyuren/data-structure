#include <cstdio>
using namespace std;

typedef int DataType;

/*
5
1 2 3 4 5
*/

struct LNode {
    DataType data;
    LNode *next;
};

void initList(LNode *&first) {
    first=new LNode;
    first->next=NULL;
}

void createList(LNode *&first,int n) {
    LNode *p=first,*s;
    for(int i=0;i<n;i++) {
        s=new LNode;
        scanf("%d",&s->data);
        p->next=s;
        p=s;
    }
    p->next=NULL;
}

bool reverseList(LNode *&first) {
    LNode *p=first->next,*r;
    if(!p) return 0;
    r=p->next;
    while(r) {
        p->next=r->next;
        r->next=first->next;
        first->next=r;
        r=p->next;
    }
}

bool displayList(LNode *first) {
    if(first->next==NULL) return 0;
    LNode *p=first->next;
    while(p) {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    return 1;
}

int main() {
    int n;
    while(~scanf("%d",&n)) {
        LNode *first;
        initList(first);
        createList(first,n);
        reverseList(first);
        displayList(first);
    }
}
