#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_V_SIZE 50
#define MAX_E_SIZE 1225
using namespace std;
/*
9
0 1 28
1 2 16
2 3 12
3 4 22
4 5 25
5 0 10
1 6 14
3 6 18
4 6 24
*/

/*
5-0: 10
2-3: 12
1-6: 14
1-2: 16
3-4: 22
4-5: 25
*/
typedef int vtype;
typedef int wtype;

struct mstEdge {
    vtype v1,v2;
    wtype weight;
};

struct vert {
    vtype name;
    int father;
};

struct edge {
    vtype v1,v2;
    wtype weight;
};

mstEdge mstTree[MAX_E_SIZE];
edge myEdge[MAX_E_SIZE];
vert myVert[MAX_V_SIZE];
int cntVert=0;
int cntEdge=0;
int cntMst=0;
int nEdge=0;
bool check_vert_input[MAX_V_SIZE];

bool cmp(edge a,edge b) {
    return a.weight<b.weight;
}

void createGraph() {
    cntVert=0;
    cntEdge=0;
    cntMst=0;
    memset(check_vert_input,0,sizeof(check_vert_input));
    for(int i=0;i<nEdge;i++) {
        scanf("%d%d%d",&myEdge[i].v1,&myEdge[i].v2,&myEdge[i].weight);
        if(!check_vert_input[myEdge[i].v1]) {
            myVert[myEdge[i].v1].name=myEdge[i].v1;
            myVert[myEdge[i].v1].father=-1;
            cntVert++;
            check_vert_input[myEdge[i].v1]=1;
        }
        if(!check_vert_input[myEdge[i].v2]) {
            myVert[myEdge[i].v2].name=myEdge[i].v2;
            myVert[myEdge[i].v2].father=-1;
            cntVert++;
            check_vert_input[myEdge[i].v2]=1;
        }
    }
}

void kruskal() {
    sort(myEdge,myEdge+nEdge,cmp);
    for(int i=0,cnt=0;i<nEdge;i++) {
        vtype v1,v2;
        v1=myEdge[i].v1;
        v2=myEdge[i].v2;
        int iroot=v1,jroot=v2;
        while(myVert[iroot].father>=0) iroot=myVert[iroot].father;
        while(myVert[jroot].father>=0) jroot=myVert[jroot].father;
        if(iroot!=jroot) {
            myVert[iroot].father=jroot;
            cnt++;
            mstTree[cntMst].v1=v1;
            mstTree[cntMst].v2=v2;
            mstTree[cntMst].weight=myEdge[i].weight;
            cntMst++;
        }
        if(cnt==cntVert-1) break;
    }
}

void printMst() {
    for(int i=0;i<cntMst;i++) {
        printf("%d-%d: %d\n",mstTree[i].v1,mstTree[i].v2,mstTree[i].weight);
    }
}

int main() {
    while(~scanf("%d",&nEdge)) {
        createGraph();
        kruskal();
        printMst();
    }
}
