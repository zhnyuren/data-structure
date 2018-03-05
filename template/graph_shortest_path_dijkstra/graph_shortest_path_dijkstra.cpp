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
0
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
wtype dist[MAX_V_SIZE];
int path[MAX_V_SIZE];

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

void dijkstra(vtype v) {
    int m=G.nVert;
    int *s=new int[m];
    wtype w,mini;
    for(int i=0;i<m;i++) {
        dist[i]=G.edge[v][i];
        s[i]=0;
        if(i!=v && dist[i]<MAXWEIGHT) path[i]=v;
        else path[i]=-1;
    }
    s[v]=1;
    dist[v]=0;
    for(int i=0;i<m-1;i++) {
        mini=MAXWEIGHT;
        int u=v;
        for(int j=0;j<m;j++) {
            if(!s[j] && dist[j]<mini) {
                u=j;
                mini=dist[j];
            }
        }
        s[u]=1;
        for(int k=0;k<m;k++) {
            w=G.edge[u][k];
            if(!s[k] && w<MAXWEIGHT && dist[u]+w<dist[k]) {
                dist[k]=dist[u]+w;
                path[k]=u;
            }
        }
    }
}

void printRes(vtype v) {
    int m=G.nVert;
    int *res=new int[m];
    for(int i=0;i<m;i++) {
        if(i!=v) {
            int j=i;
            int k=0;
            while(j!=v) {
                res[k++]=j;
                j=path[j];
            }
            printf("TO %d: ",G.vertList[i]);
            printf("%d ",G.vertList[v]);
            while(k>0) printf("%d ",G.vertList[res[--k]]);
            printf("\nLENGTH: %d\n",dist[i]);
        }
    }
}

int main() {
    while(~scanf("%d",&n)) {
        createGraph();
        vtype v;
        scanf("%d",&v);
        dijkstra(v);
        printRes(v);
    }
}
