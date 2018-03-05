#include <cstdio>
#define MAXSIZE 100
using namespace std;

typedef int DataType;

struct sqlist {
    DataType data[MAXSIZE];
    int len;
};

sqlist L;

int bSearch(sqlist L,DataType x) {
    int low=0,high=L.len-1,mid;
    while(low<=high) {
        mid=(low+high)/2;
        if(x<L.data[mid]) high=mid-1;
        else if(x>L.data[mid]) low=mid+1;
        else return mid;
    }
    return -1;
}

int bSearchRec(sqlist L,DataType x,int low,int high) {
    int mid;
    if(low<=high) {
        mid=(low+high)/2;
        if(x<L.data[mid]) mid=bSearchRec(L,x,low,mid-1);
        else if(x>L.data[mid]) mid=bSearchRec(L,x,mid+1,high);
        else return mid;
    }
    else return -1;
}

int main() {
    int n;
    while(~scanf("%d",&n)) {
        L.len=n;
        for(int i=0;i<n;i++) scanf("%d",&L.data[i]);
        DataType x;
        scanf("%d",&x);
        printf("%d\n",bSearch(L,x));
        printf("%d\n",bSearchRec(L,x,0,L.len-1));
    }
}
