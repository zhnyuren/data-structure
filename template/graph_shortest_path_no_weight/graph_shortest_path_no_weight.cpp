#include <cstdio>
#include <cstring>
#include <queue>
#define MAX_E_SIZE 45
#define MAX_V_SIZE 10
#define MAXWEIGHT 9999999
using namespace std;

/*
9
0 1
1 2
2 3
3 4
4 5
5 0
1 6
3 6
4 6
0
*/

typedef int vtype;

struct AMgraph {
    int nEdge,nVert;
    int edge[MAX_E_SIZE][MAX_E_SIZE];
    vtype vertList[MAX_V_SIZE];
};

bool check_vert_input[MAX_V_SIZE];
AMgraph G;
int n=0;
int dist[MAX_V_SIZE];
int path[MAX_V_SIZE];

void createGraph() {
    memset(check_vert_input,0,sizeof(check_vert_input));
    memset(G.edge,0,sizeof(G.edge));
    G.nVert=0;
    G.nEdge=n;
    for(int i=0;i<G.nEdge;i++) {
        vtype v1,v2;
        scanf("%d%d",&v1,&v2);
        if(!check_vert_input[v1]) {
            G.vertList[G.nVert++]=v1;
            check_vert_input[v1]=true;
        }
        if(!check_vert_input[v2]) {
            G.vertList[G.nVert++]=v2;
            check_vert_input[v2]=true;
        }
        G.edge[v1][v2]=1;
        G.edge[v2][v1]=1;//undirected graph
    }
}

void shortestPathNoWeight(vtype v) {
    int m=G.nVert;
    queue<int> Q;
    for(int i=0;i<m;i++) {
        dist[i]=MAXWEIGHT;
        if(G.edge[v][i]) path[i]=v;
        else path[i]-1;
    }
    dist[v]=0;
    Q.push(v);
    while(!Q.empty()) {
        v=Q.front();
        Q.pop();
        for(int i=0;i<m;i++) {
            if(G.edge[v][i] && dist[i]==MAXWEIGHT) {
                dist[i]=dist[v]+1;
                path[i]=v;
                Q.push(i);
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
        shortestPathNoWeight(v);
        printRes(v);
    }
}
