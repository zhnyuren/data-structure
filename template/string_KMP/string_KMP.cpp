#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

struct sqstring {
    char data[100];
    int len=0;
}S,T;

void getNext(sqstring T,int next[]) {
    int j=0,k=-1;
    next[0]=-1;
    while(j<T.len) {
        while(k>=0 && T.data[j]!=T.data[k]) k=next[k];
        j++;k++;
        if(T.data[j]==T.data[k]) next[j]=next[k];
        else next[j]=k;
    }
}

int patternMatching(sqstring S,sqstring T,int next[]) {
    int i=0,j=0;
    while(i<S.len && j<T.len){
        if(j==-1 || S.data[i]==T.data[j]) {i++; j++;}
        else j=next[j];
        if(j==T.len) return i-j;
    }
    return -1;
}

int main() {
    char a[100];
    cin>>a;
    char b[100];
    cin>>b;
    for(int i=0;i<=strlen(a);i++){ //i<strlen(a) or i<=strlen(a)
        S.data[i]=a[i];
    }
    S.len=strlen(a);
    for(int i=0;i<=strlen(b);i++){ //i<strlen(b) or i<=strlen(b)
        T.data[i]=b[i];
    }
    T.len=strlen(b);
    int next[T.len];
    getNext(T,next);
    printf("next:");
    for(int i=0;i<T.len;i++) printf("%d ",next[i]);
    printf("\n");
    printf("%d\n",patternMatching(S,T,next));
}
