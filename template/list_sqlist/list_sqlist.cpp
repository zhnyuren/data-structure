#include <iostream>
#include <string>
#define maxSize 100
using namespace std;

typedef int DataType;

typedef struct _sqlist {
    DataType data[maxSize];
    int len;
}sqlist;

void initlist(sqlist &l) {
    l.len=0;
}

int isEmpty(sqlist l) {
    return (l.len==0)?1:0;
}

int isFull(sqlist l) {
    return (l.len==maxSize)?1:0;
}

int searchlist(sqlist l,DataType x) {
    for(int i=0;i<l.len;i++) {
        if(l.data[i]==x) return i+1;
    }
    return -1;
}

int insertlist(sqlist &l,int i,DataType x) {
    if(l.len==maxSize) return 0;
    if(i<1 || i>l.len+1) return 0;
    for(int j=l.len-1;j>=i-1;j--) {
        l.data[j+1]=l.data[j];
    }
    l.data[i-1]=x;
    l.len++;
    return 1;
}

int deletelist(sqlist &l,int i,DataType &x) {
    if(l.len==0) return 0;
    if(i<1 || i>l.len+1) return 0;
    x=l.data[i-1];
    for(int j=i-1;j<l.len-1;j++) {
        l.data[j]=l.data[j+1];
    }
    l.len--;
    return 1;
}

int main() {
    sqlist l;
    initlist(l);
    string op;
    while(cin>>op) {
        if(op=="ins") {
            int i;
            DataType x;
            cin>>i>>x;
            if(!insertlist(l,i,x)) cout<<"error!\n";
        }
        else if(op=="del") {
            int i;
            DataType x;
            cin>>i;
            if(!deletelist(l,i,x)) cout<<"error!\n";
        }
        else if(op=="dis") {
            for(int i=0;i<l.len;i++) {
                cout<<l.data[i]<<" ";
            }
            cout<<endl;
        }
    }
}
