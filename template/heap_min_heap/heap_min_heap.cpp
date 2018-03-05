#include <iostream>
#define HEAPSIZE 128
using namespace std;
//53 17 78 9 45 65 87 23

typedef struct _HDataType {
    int key;
}HDataType;

typedef struct heap {
    HDataType data[HEAPSIZE];
    int number;
}minHeap;

void siftDown(minHeap &H,int start,int m) {
    int i=start;
    HDataType tmp=H.data[i];
    for(int j=2*i+1;j<=m;j=2*j+1) {//find the last node with no children
        if(j<m && H.data[j].key>H.data[j+1].key) j++;//choose the smaller child
        if(tmp.key<=H.data[j].key) break;//if the sequence is correct, break
        else {
            H.data[i]=H.data[j];//if not, let the smaller one go up
            i=j;//let the index go down until to the leaf node
        }
    }
    H.data[i]=tmp;//put the start one on the right place
}

void siftUp(minHeap &H,int start) {
    HDataType tmp=H.data[start];
    int j=start;//son
    int i=(j-1)/2;//father
    while(j>0) {
        if(H.data[i].key<=tmp.key) break;//right sequence
        else {
            H.data[j]=H.data[i];//let the bigger one go down
            j=i;//index goes up
            i=(i-1)/2;//index goes up
        }
    }
    H.data[j]=tmp;
}

void createMinHeap(minHeap &H,HDataType arr[],int n) {
    for(int i=0;i<n;i++) H.data[i]=arr[i];
    H.number=n;
    for(int i=(H.number-2)/2;i>=0;i--) siftDown(H,i,H.number-1);
}

int insertHeap(minHeap &H,HDataType x) {
    if(H.number==HEAPSIZE) return 0;
    H.data[H.number]=x;
    siftUp(H,H.number);
    H.number++;
    return 1;
}

int removeTheTopHeap(minHeap &H,HDataType &x){
    if(H.number==0) return 0;
    x=H.data[0];
    H.data[0]=H.data[H.number-1];
    H.number--;
    siftDown(H,0,H.number-1);
    return 1;
}

int printByLevel(minHeap H) {
    for(int i=0;i<H.number;i++) cout<<H.data[i].key<<" ";
    cout<<endl;
}

int main() {
    HDataType arr[1000];
    int n;
    while(cin>>n) {
        for(int i=0;i<n;i++) cin>>arr[i].key;
        minHeap H;
        createMinHeap(H,arr,n);
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
