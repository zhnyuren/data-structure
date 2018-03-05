#include <cstdio>
#define MAXSIZE 100
using namespace std;
/*
10
2 4 1 10 3 7 8 9 5 6
10
3 4 6 6 2 4 19 3 12 1
*/
typedef int DataType;

struct sqlist {
    DataType data[MAXSIZE];
    int len;
};

sqlist L;

void shell_insert_sort(sqlist &L) {
    for(int dk=L.len/2;dk>=1;dk/=2) {
        for(int i=dk;i<=L.len-1;i++) {
            if(L.data[i-dk]>L.data[i]) {
                int j;
                DataType tmp=L.data[i];
                for(j=i-dk;j>=0 && tmp<L.data[j];j-=dk) L.data[j+dk]=L.data[j];
                L.data[dk+j]=tmp;
            }
        }
        printf("dk: %d\nthis loop: ",dk);
        for(int i=0;i<L.len;i++) printf("%d ",L.data[i]);
        printf("\n");
    }
}

int main() {
    int n;
    while(~scanf("%d",&n)) {
        L.len=n;
        for(int i=0;i<n;i++) scanf("%d",&L.data[i]);
        shell_insert_sort(L);
        for(int i=0;i<n;i++) printf("%d ",L.data[i]);
        printf("\n");
    }
}
