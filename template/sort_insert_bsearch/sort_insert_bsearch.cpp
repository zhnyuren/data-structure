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

void insert_bsearch_sort(sqlist &L) {
    for(int i=1;i<=L.len-1;i++) {
        if(L.data[i-1]>L.data[i]) {
            DataType tmp=L.data[i];
            int low=0,high=i-1;
            while(low<=high) {
                int mid=(low+high)/2;
                if(tmp<L.data[mid]) high=mid-1;
                else low=mid+1;
            }
            int j;
            for(j=i-1;j>=low;j--) L.data[j+1]=L.data[j];
            L.data[low]=tmp;
        }
    }
}

int main() {
    int n;
    while(~scanf("%d",&n)) {
        L.len=n;
        for(int i=0;i<n;i++) scanf("%d",&L.data[i]);
        insert_bsearch_sort(L);
        for(int i=0;i<n;i++) printf("%d ",L.data[i]);
        printf("\n");
    }
}
