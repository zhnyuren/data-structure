#include <cstdio>
#define MAXSIZE 100
using namespace std;

typedef int DataType;

/*
10
2 4 1 10 3 7 8 9 5 6
10
3 4 6 6 2 4 19 3 12 1
*/

struct sqlist {
    DataType data[MAXSIZE];
    int len;
};

sqlist L;

void select_sort(sqlist &L) {
    for(int i=0;i<L.len;i++) {
        int k=i;
        for(int j=i+1;j<L.len;j++) {
            if(L.data[j]<L.data[k]) k=j;
        }
        if(k!=i) {
            DataType tmp=L.data[i];
            L.data[i]=L.data[k];
            L.data[k]=tmp;
        }
    }
}

int main() {
    int n;
    while(~scanf("%d",&n)) {
        L.len=n;
        for(int i=0;i<n;i++) scanf("%d",&L.data[i]);
        select_sort(L);
        for(int i=0;i<n;i++) printf("%d ",L.data[i]);
        printf("\n");
    }
}

