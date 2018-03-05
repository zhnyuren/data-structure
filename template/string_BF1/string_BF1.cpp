#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

struct sqstring {
    char data[100];
    int len=0;
}S,T;

int index(sqstring S,sqstring T) {
    int i,j,last=S.len-T.len;
    for(i=0;i<=last;i++){
        for(j=0;j<T.len;j++){
            if(S.data[i+j]!=T.data[j]) break;
        }
        if(j==T.len) return i;
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
    printf("%d\n",index(S,T));
}
