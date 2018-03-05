#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <limits.h>
#include <float.h>
#define MAX_V_SIZE 10
#define MAX_E_SIZE 45
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
    int weight;
};

struct AMgraph {
    wtype edge[MAX_E_SIZE][MAX_E_SIZE];
    vtype vertList[MAX_V_SIZE];
    int nVert,nEdge;
};

mstEdge mstTree[MAX_E_SIZE];
int cntMst=0;
bool check_vert_input[MAX_V_SIZE];
bool vmst[MAX_V_SIZE];
AMgraph G;
int n=0;

void createGraph() {
    memset(check_vert_input,0,sizeof(check_vert_input));
    memset(vmst,0,sizeof(vmst));
    cntMst=0;
    G.nVert=0;
    G.nEdge=n;
    for(int i=0;i<MAX_E_SIZE;i++) {
        for(int j=0;j<MAX_E_SIZE;j++) {
            if(i==j) G.edge[i][j]=0;
            else G.edge[i][j]=FLT_MAX;
        }
    }
    for(int i=0;i<G.nEdge;i++) {
        vtype v1,v2;
        wtype w;
        scanf("%d%d%d",&v1,&v2,&w);
        if(!check_vert_input[v1]) {
            G.vertList[G.nVert++]=v1;
            check_vert_input[v1]=true;
        }
        if(!check_vert_input[v2]) {
            G.vertList[G.nVert++]=v2;
            check_vert_input[v2]=true;
        }
        G.edge[v1][v2]=w;
        G.edge[v2][v1]=w;
    }
}

void prim() {
    vmst[G.vertList[0]]=true;
    while(cntMst!=G.nVert-1) {
        wtype mini=999999;
        int miniIndex1=0,miniIndex2=0;
        int v1,v2,w;
        for(int i=0;i<G.nVert;i++) {
            if(vmst[G.vertList[i]]==1) {
                v1=G.vertList[i];
                for(int j=0;j<MAX_V_SIZE;j++) {
                    if(G.edge[v1][j]!=0 && G.edge[v1][j]!=FLT_MAX && G.edge[v1][j]<mini && vmst[j]==0) {
                        mini=G.edge[v1][j];
                        miniIndex1=v1;
                        miniIndex2=j;
                    }
                }
            }
        }
        vmst[miniIndex2]=1;
        mstTree[cntMst].v1=miniIndex1;
        mstTree[cntMst].v2=miniIndex2;
        mstTree[cntMst].weight=mini;
        cntMst++;
    }
}

void printMst() {
    for(int i=0;i<cntMst;i++) {
        printf("%d-%d: %d\n",mstTree[i].v1,mstTree[i].v2,mstTree[i].weight);
    }
}

int main() {
    while(~scanf("%d",&n)) {
        createGraph();
        prim();
        printMst();
    }
}
