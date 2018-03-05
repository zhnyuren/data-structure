#include <cstdio>
#include <algorithm>
#define MAXSIZE 100
using namespace std;

/*
10
2 4 6 8 10 12 14 16 18 20
8
*/

int data[MAXSIZE];
int n;

int binarySearch(int x) {
    int low=0,high=n-1,mid;
    while(low<=high) {
        mid=(low+high)/2;
        if(x<data[mid]) high=mid-1;
        else if(x>data[mid]) low=mid+1;
        else return mid;
    }
    return -1;
}

int binarySearchRec(int x,int low,int high) {
    if(low<=high) {
        int mid=(high+low)/2;
        if(x<data[mid]) return binarySearchRec(x,low,mid-1);
        else if(x>data[mid]) return binarySearchRec(x,mid+1,high);
        else return mid;
    }
    return -1;
}

int main() {
    while(~scanf("%d",&n)) {
        for(int i=0;i<n;i++) scanf("%d",&data[i]);
        sort(data,data+n);
//        for(int i=0;i<n;i++) printf("%d ",data[i]);
        int x;
        scanf("%d",&x);
        int l=0,h=n-1;
        printf("%d\n",binarySearchRec(x,l,h));
    }
}
