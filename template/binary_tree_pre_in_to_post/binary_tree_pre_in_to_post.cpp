#include <cstdio>
using namespace std;

typedef int DataType;

typedef struct node {
    DataType data;
    struct node *lchild,*rchild;
}BiTNode, *BinTree;

BiTNode* createToPost(DataType *PRE,DataType *IN,int n) {
    if(n==0) return nullptr;
    DataType *p=IN;
    int k=0;
    while(*PRE!=*p) {p++; k++;}
    BiTNode *t=new BiTNode;
    t->data=*PRE;
//    printf("\ncurrent:%d\n",t->data);
    t->lchild=createToPost(PRE+1,IN,k);
    t->rchild=createToPost(PRE+k+1,IN+k+1,n-k-1);
    return t;
}

void PostOrder(BiTNode *root) {
    if(root!=nullptr) {
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        printf("%d ",root->data);
    }
}

int main() {
    int n;
    while(~scanf("%d",&n)) {
        DataType* PRE=new DataType[n];
        DataType* IN=new DataType[n];
        BiTNode *root;
        for(int i=0;i<n;i++) {
            scanf("%d",&PRE[i]);
        }
        for(int i=0;i<n;i++) {
            scanf("%d",&IN[i]);
        }
        root=createToPost(PRE,IN,n);
        PostOrder(root);
        printf("\n");
    }
}

