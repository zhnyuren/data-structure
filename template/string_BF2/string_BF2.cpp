#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

struct sqstring {
    char data[100];
    int len=0;
}S,T;

int index(sqstring S,sqstring T) {
    int i=0,j=0;
    while(i<S.len && j<T.len){
        if(S.data[i]==T.data[j]) {i++; j++;}
        else {i=i-j+1; j=0;}
        if(j==T.len) return i-j;
    }
    return 0;
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
    printf("%d\n",index(S,T));
}

