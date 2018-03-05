#include <cstdio>
using namespace std;

struct node {
    int x,y;
    int father;
};

node vert[105];

int findroot(int x) {
    while(vert[x].father>=0) x=vert[x].father;
    return x;
}

int main() {
    int n;
    while(~scanf("%d",&n)) {
        int cnt=0;
        for(int i=0;i<n;i++) {
            scanf("%d%d",&vert[i].x,&vert[i].y);
            vert[i].father=-1;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(j!=i) {
                    if(vert[i].x==vert[j].x || vert[i].y==vert[j].y) {
                        int iroot,jroot;
                        iroot=findroot(i);
                        jroot=findroot(j);
                        if(iroot!=jroot) vert[iroot].father=jroot;
                    }
                }
            }
        }
        for(int i=0;i<n;i++) {
            if(vert[i].father==-1) cnt++;
        }
        printf("%d\n",cnt-1);
    }
}
