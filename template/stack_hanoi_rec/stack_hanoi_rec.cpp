#include <cstdio>
using namespace std;

void hanoi(char start,char tmp,char dest,int m) {
    if(m==1) printf("%c -> %c\n",start,dest);
    else {
        hanoi(start,dest,tmp,m-1);
        hanoi(start,tmp,dest,1);
        hanoi(tmp,start,dest,m-1);
    }
}

int main() {
    int n;
    while(~scanf("%d",&n)) {
        hanoi('A','B','C',n);
    }
}
