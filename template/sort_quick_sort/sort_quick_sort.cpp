#include <cstdio>
#define MAXSIZE 100
using namespace std;

typedef int DataType;

/*
10
2 4 1 10 3 7 8 9 5 6
10
3 4 6 6 2 4 19 3 12 1
6
21 25 49 25 16 08
*/

struct sqlist {
    DataType data[MAXSIZE];
    int len;
};

sqlist L;

int partition1(sqlist &L,int low,int high) {
    DataType pivot=L.data[low];
    int k=low;
    for(int i=low+1;i<=high;i++) {
        if(L.data[i]<pivot) {
            k++;
            if(k!=i) {
                DataType tmp=L.data[k];
                L.data[k]=L.data[i];
                L.data[i]=tmp;
            }

        }
    }
    L.data[low]=L.data[k];
    L.data[k]=pivot;
    return k;
}

int partition2(sqlist &L,int low,int high) {
    int pivot=L.data[low];
    while(low<high) {
        while(low<high && L.data[high]>=pivot) high--;
        L.data[low]=L.data[high];
        while(low<high && L.data[low]<=pivot) low++;
        L.data[high]=L.data[low];
    }
    L.data[low]=pivot;
    return low;
}

void quick_sort(sqlist &L,int low,int high) {
    if(low<high) {
        int pivot_pos=partition2(L,low,high);
        quick_sort(L,low,pivot_pos-1);
        quick_sort(L,pivot_pos+1,high);
    }
}

int main() {
    int n;
    while(~scanf("%d",&n)) {
        L.len=n;
        for(int i=0;i<n;i++) scanf("%d",&L.data[i]);
        quick_sort(L,0,L.len-1);
        for(int i=0;i<n;i++) printf("%d ",L.data[i]);
        printf("\n");
    }
}
