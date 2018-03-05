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

void bubble_sort(sqlist &L) {
    for(int i=0;i<L.len;i++) {
        bool exchange=false;
        for(int j=0;j<L.len-1-i;j++) {
            printf("haha\n");
            if(L.data[j]>L.data[j+1]) {
                DataType tmp=L.data[j];
                L.data[j]=L.data[j+1];
                L.data[j+1]=tmp;
                exchange=true;
            }
        }
        if(!exchange) break;
    }
}

int main() {
    int n;
    while(~scanf("%d",&n)) {
        L.len=n;
        for(int i=0;i<n;i++) scanf("%d",&L.data[i]);
        bubble_sort(L);
        for(int i=0;i<n;i++) printf("%d ",L.data[i]);
        printf("\n");
    }
}
