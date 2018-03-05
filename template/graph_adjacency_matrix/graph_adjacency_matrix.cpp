#include <iostream>
#include <cstdio>
#include <queue>
#define MAX_VERT 20
#define MAX_WEIGHT 999999
using namespace std;

/*
5 6
1 2 3 4 5
1 2 24
1 3 46
2 3 15
2 5 67
3 4 53
5 4 31
*/

typedef int vtype;
typedef int wtype;

typedef struct graph {
    int numVert,numEdge;
    vtype *vertList;
    wtype **edge;
}AMgraph;

void initGraph(AMgraph &G) {
    G.numVert=0;
    G.numEdge=0;
    G.vertList=new vtype[MAX_VERT];
    G.edge=new wtype* [MAX_VERT];
    for(int i=0;i<MAX_VERT;i++) {
        G.edge[i]=new wtype[MAX_VERT];
    }
    for(int i=0;i<MAX_VERT;i++) {
//        G.vertList[i]=0;
        for(int j=0;j<MAX_VERT;j++) {
            G.edge[i][j]=((i==j)?0:MAX_WEIGHT);
        }
    }
}

int getVertPos(AMgraph &G,vtype x) {
    for(int i=0;i<G.numVert;i++) {
        if(G.vertList[i]==x) return i;
    }
    return -1;
}

vtype getVertValue(AMgraph &G,int pos) {
    if(pos>=0 && pos<G.numVert) return G.vertList[pos];
    return 0;
}

wtype getVertWeight(AMgraph &G,int v1,int v2) {
    if(v1>=0 && v1<G.numVert && v2>=0 && v2<G.numVert) return G.edge[v1][v2];
    return 0;
}

int firstNeighbor(AMgraph &G,int v) {
    if(v>=0 && v<G.numVert) {
        for(int i=0;i<G.numVert;i++) {
            if(G.edge[v][i]>0 && G.edge[v][i]<MAX_WEIGHT) return i;
        }
    }
    return -1;
}

int nextNeighbor(AMgraph &G,int v1,int v2) {
    if(v1>0 && v1<G.numVert && v2>0 && v2<G.numVert) {
        for(int i=v2+1;i<G.numVert;i++) {
            if(G.edge[v1][i]>0 && G.edge[v1][i]<MAX_WEIGHT) return i;
        }
    }
    return -1;
}

void createGraph(AMgraph &G,int nVert,int mEdge) {
    int i,j,k;
    vtype v1,v2;
    wtype weight;
    G.numVert=nVert;
    G.numEdge=mEdge;
    for(i=0;i<G.numVert;i++) {
        cin>>G.vertList[i];
    }
    i=0;
    while(i<G.numEdge) {
        cin>>v1>>v2>>weight;
        j=getVertPos(G,v1);
        k=getVertPos(G,v2);
        if(j>=0 && k>=0) {
            G.edge[j][k]=G.edge[k][j]=weight;//undirected graph
//            G.edge[j][k]=weight;//directed graph
            i++;
        }
        else cout<<"wrong input!\n";
    }
}

void dfs(AMgraph &G,bool vis[],int v) {
    cout<<getVertValue(G,v)<<" ";
    vis[v]=1;
    for(int i=0;i<G.numVert;i++) {
        if(G.edge[v][i]>0 && G.edge[v][i]<MAX_WEIGHT && !vis[i]) dfs(G,vis,i);
    }
}

void dfs_traversal(AMgraph &G) {
    bool *vis=new bool[G.numVert];
    for(int i=0;i<G.numVert;i++) vis[i]=0;
    for(int i=0;i<G.numVert;i++) {
        if(!vis[i]) dfs(G,vis,i);
    }
}

void bfs_traversal(AMgraph &G,int v) {
    queue<int> Q;
    Q.push(v);
    bool *vis=new bool[G.numVert];
    vis[v]=1;
    while(!Q.empty()) {
        int out=Q.front();
        Q.pop();
        cout<<getVertValue(G,out)<<" ";
        for(int i=0;i<G.numVert;i++) {
            if(G.edge[out][i]>0 && G.edge[out][i]<MAX_WEIGHT && !vis[i]) {
                Q.push(i);
                vis[i]=1;
            }
        }
    }
}

void printGraph(AMgraph &G) {
    wtype w;
    cout<<"number of vertices:"<<G.numVert<<endl;
    cout<<"vertices are:"<<endl;
    for(int i=0;i<G.numVert;i++) {
        cout<<G.vertList[i]<<endl;
    }
    cout<<"number of edges:"<<G.numEdge<<endl;
    cout<<"edges are:"<<endl;
    for(int i=0;i<G.numVert;i++) {
        for(int j=0;j<G.numVert;j++) {
            w=G.edge[i][j];
            if(w>0 && w<MAX_WEIGHT) {
                cout<<"("<<getVertValue(G,i)<<","<<getVertValue(G,j)<<","<<w<<")"<<endl;
            }
        }
    }
}

int main() {
    AMgraph G;
    initGraph(G);
    int n,m;
    cin>>n>>m;
    createGraph(G,n,m);
    printGraph(G);
    bfs_traversal(G,0);
    return 0;
}
