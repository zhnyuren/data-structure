#include <cstdio>
#define MAXSIZE 100
using namespace std;

typedef int DataType;

/*
10
2 4 1 10 3 7 8 9 5 6
10
3 4 6 6 2 4 19 3 12 1
10
1 2 3 4 5 10 6 7 8 9
*/

struct sqlist {
    DataType data[MAXSIZE];
    int len;
};

sqlist L;

void direct_insert_sort(sqlist &L) {
    DataType tmp;
    for(int i=1;i<=L.len-1;i++) {
        printf("haha\n");
        if(L.data[i-1]>L.data[i]) {
            tmp=L.data[i];
            int j;
            for(j=i-1;j>=0 && tmp<L.data[j];j--) L.data[j+1]=L.data[j];
            L.data[j+1]=tmp;
        }
    }
}

int main() {
    int n;
    while(~scanf("%d",&n)) {
        L.len=n;
        for(int i=0;i<n;i++) scanf("%d",&L.data[i]);
        direct_insert_sort(L);
        for(int i=0;i<n;i++) printf("%d ",L.data[i]);
        printf("\n");
    }
}
