#include <cstdio>
#include <cstring>
#define MAX_E_SIZE 45
#define MAX_V_SIZE 10
#define MAXWEIGHT 9999999
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

typedef int vtype;
typedef int wtype;

struct AMgraph {
    int nEdge,nVert;
    wtype edge[MAX_E_SIZE][MAX_E_SIZE];
    vtype vertList[MAX_V_SIZE];
};

bool check_vert_input[MAX_V_SIZE];
AMgraph G;
int n=0;
int path[MAX_V_SIZE][MAX_V_SIZE];
wtype RES[MAX_V_SIZE][MAX_V_SIZE];

void createGraph() {
    memset(check_vert_input,0,sizeof(check_vert_input));
    G.nVert=0;
    G.nEdge=n;
    for(int i=0;i<MAX_E_SIZE;i++) {
        for(int j=0;j<MAX_E_SIZE;j++) {
            if(i==j) G.edge[i][j]=0;
            else G.edge[i][j]=MAXWEIGHT;
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
        G.edge[v2][v1]=w;//undirected graph
    }
}

void floyd() {
    int m=G.nVert;
    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            RES[i][j]=G.edge[i][j];
            if(i!=j && RES[i][j]<MAXWEIGHT) path[i][j]=i;
            else path[i][j]=-1;
        }
    }
    for(int k=0;k<m;k++) {
        for(int i=0;i<m;i++) {
            for(int j=0;j<m;j++) {
                if(RES[i][k]+RES[k][j]<RES[i][j]) {
                    RES[i][j]=RES[i][k]+RES[k][j];
                    path[i][j]=path[k][j];
                }
            }
        }
    }
}

void printRes() {
    int m=G.nVert;
    int *ans=new int[m];
    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            if(i!=j) {
                int k=j;
                int cnt=0;
                while(k!=i) {
                    ans[cnt++]=k;
                    k=path[i][k];
                }
                printf("FROM %d TO %d: ",G.vertList[i],G.vertList[j]);
                printf("%d ",G.vertList[i]);
                while(cnt>0) printf("%d ",G.vertList[ans[--cnt]]);
                printf("\nLENGTH: %d\n",RES[i][j]);
            }
        }
    }
}

int main() {
    while(~scanf("%d",&n)) {
        createGraph();
        floyd();
        printRes();
    }
}
