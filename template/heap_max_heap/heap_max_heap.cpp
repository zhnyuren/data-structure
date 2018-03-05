#include <iostream>
#define HEAPSIZE 128
using namespace std;

typedef struct _HDataType {
    int key;
}HDataType;

typedef struct heap {
    HDataType data[HEAPSIZE];
    int number;
}maxHeap;

void siftDown(maxHeap &H,int start,int m) {
    int i=start;
    HDataType tmp=H.data[i];
    for(int j=2*i+1;j<=m;j=2*j+1) {
        if(j<m && H.data[j].key<H.data[j+1].key) j++;
        if(tmp.key>=H.data[j].key) break;
        else {
            H.data[i]=H.data[j];
            i=j;
        }
    }
    H.data[i]=tmp;
}

void siftUp(maxHeap &H,int start) {
    HDataType tmp=H.data[start];
    int j=start;//son
    int i=(j-1)/2;//father
    while(j>0) {
        if(H.data[i].key>=tmp.key) break;
        else {
            H.data[j]=H.data[i];
            j=i;
            i=(i-1)/2;
        }
    }
    H.data[j]=tmp;
}

void createMaxHeap(maxHeap &H,HDataType arr[],int n) {
    for(int i=0;i<n;i++) H.data[i]=arr[i];
    H.number=n;
    for(int i=(H.number-2)/2;i>=0;i--) siftDown(H,i,H.number-1);
}

int insertHeap(maxHeap &H,HDataType x) {
    if(H.number==HEAPSIZE) return 0;
    H.data[H.number]=x;
    siftUp(H,H.number);
    H.number++;
    return 1;
}

int removeTheTopHeap(maxHeap &H,HDataType &x) {
    if(H.number==0) return 0;
    x=H.data[0];
    H.data[0]=H.data[H.number-1];
    H.number--;
    siftDown(H,0,H.number-1);
    return 1;
}

int printByLevel(maxHeap &H) {
    for(int i=0;i<H.number;i++) cout<<H.data[i].key<<" ";
    cout<<endl;
}

int main() {
    HDataType arr[1000];
    int n;
    while(cin>>n) {
        for(int i=0;i<n;i++) cin>>arr[i].key;
        maxHeap H;
        createMaxHeap(H,arr,n);
        printByLevel(H);

        HDataType x;
        cout<<"insert:";
        cin>>x.key;
        insertHeap(H,x);
        printByLevel(H);

        int removeNum;
        cin>>removeNum;
        cout<<"remove:";
        for(int i=0;i<removeNum;i++) {
            HDataType y;
            removeTheTopHeap(H,y);
            cout<<y.key<<" ";
        }
        cout<<endl;
    }
}
