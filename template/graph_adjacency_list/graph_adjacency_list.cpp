#include <iostream>
#include <queue>
#include <stack>
#define MAX_VERT 30
#define MAX_WEIGHT 999999
using namespace std;

/*
5 6
a b c d e
a b 24
a c 46
b c 15
b e 67
c d 53
e d 31
*/

typedef char vtype;//typedef int vtype;
typedef int wtype;

typedef struct _edgeNode {
    wtype cost;
    int dest;
    struct _edgeNode *next;
}edgeNode;

typedef struct _vertNode {
    vtype data;
    struct _edgeNode *first;
}vertNode;

typedef struct _ALgraph {
    vertNode *vertList;
    int numVert,numEdge;
}ALgraph;

void initGraph(ALgraph &G) {
    G.numEdge=0;
    G.numVert=0;
    G.vertList=new vertNode[MAX_VERT];
    for(int i=0;i<MAX_VERT;i++) {
        G.vertList[i].first=nullptr;
    }
}

int getVertPos(ALgraph &G,vtype x) {
    for(int i=0;i<MAX_VERT;i++) {
        if(G.vertList[i].data==x) {
            return i;
        }
    }
    return -1;
}

vtype getVertValue(ALgraph &G,int pos) {
    if(pos>=0 && pos<G.numVert) {
        return G.vertList[pos].data;
    }
    return 'null';//return 0;
}

wtype getVertWeight(ALgraph &G,int v1,int v2) {
    if(v1>=0 && v1<G.numVert && v2>=0 && v2<G.numVert) {
        edgeNode *p=G.vertList[v1].first;
        while(p!=nullptr && p->dest!=v2) {
            p=p->next;
        }
        if(p!=nullptr) {
            return p->cost;
        }
    }
    return 0;
}

int firstNeighbor(ALgraph &G,int v) {
    if(v>=0 && v<G.numVert) {
        edgeNode *p=G.vertList[v].first;
        if(p!=nullptr) {
            return p->dest;
        }
    }
    return -1;
}

int nextNeighbor(ALgraph &G,int v1,int v2) {
    if(v1>=0 && v1<G.numVert && v2>=0 && v2<G.numVert) {
        edgeNode *p=G.vertList[v1].first;
        while(p!=nullptr && p->dest!=v2) {
            p=p->next;
        }
        if(p!=nullptr && p->next!=nullptr) {
            return p->next->dest;
        }
    }
    return -1;
}


void createGraph(ALgraph &G,int nVert,int mEdge) {
    int i,j,k;
    vtype v1,v2;
    wtype weight;
    edgeNode *p,*r;
    G.numVert=nVert;
    G.numEdge=mEdge;
    for(i=0;i<nVert;i++) {
        cin>>G.vertList[i].data;
    }
    i=0;
    while(i<mEdge) {
        cin>>v1>>v2>>weight;
        j=getVertPos(G,v1);
        k=getVertPos(G,v2);
        if(j!=-1 && k!=-1) {
            p=G.vertList[j].first;
            while(p!=nullptr && p->dest!=k) {
                p=p->next;
            }
            if(p==nullptr) {
                r=new edgeNode;
                r->dest=k;
                r->cost=weight;
                r->next=G.vertList[j].first;
                G.vertList[j].first=r;
                r=new edgeNode;
                r->dest=j;
                r->cost=weight;
                r->next=G.vertList[k].first;
                G.vertList[k].first=r;
                i++;
            }
            else {
                cout<<"repeated input!"<<endl;
            }
        }
        else {
            cout<<"wrong input!"<<endl;
        }
    }
}

void printGraph(ALgraph &G) {
    edgeNode *p;
    cout<<"number of vertices: "<<G.numVert<<endl;
    cout<<"vertices are: "<<endl;
    for(int i=0;i<G.numVert;i++) {
        cout<<G.vertList[i].data<<endl;
    }
    cout<<"number of edges: "<<G.numEdge<<endl;
    cout<<"edges are: "<<endl;
    for(int i=0;i<G.numVert;i++) {
        for(p=G.vertList[i].first;p!=nullptr;p=p->next) {
            cout<<"("<<getVertValue(G,i)<<","<<getVertValue(G,p->dest)<<","<<p->cost<<")"<<endl;
        }
    }
}

void dfs_stack(ALgraph &G,int v,int visited[]) {
    stack<int> S;
    S.push(v);
    cout<<getVertValue(G,v)<<" ";
    visited[v]=1;
    int w=firstNeighbor(G,v);
    while(!S.empty()) {
        while(w!=-1 && visited[w]==0) {
            S.push(w);
            cout<<getVertValue(G,w)<<" ";
            visited[w]=1;
            w=firstNeighbor(G,w);
        }
        v=S.top();
        bool found=false;
        for(int i=firstNeighbor(G,v);i!=-1;i=nextNeighbor(G,v,i)) {
            if(visited[i]==0) {
                found=true;
                w=i;
                break;
            }
        }
        if(!found) S.pop();
    }
}

void dfs(ALgraph &G,int v,int visited[]) {
    cout<<getVertValue(G,v)<<" ";
    visited[v]=1;
    int w=firstNeighbor(G,v);
    while(w!=-1) {
        if(visited[w]==0) dfs(G,w,visited);
        w=nextNeighbor(G,v,w);
    }
}

void dfs_traversal(ALgraph &G,int v) {
    int *visited=new int[G.numVert];
    for(int i=0;i<G.numVert;i++) {
        visited[i]=0;
    }
    dfs(G,v,visited);
//    dfs_stack(G,v,visited);
    cout<<endl;
    delete []visited;
}

void bfs_traversal(ALgraph &G,int v) {
    int v1,v2;
    int *visited=new int[G.numVert];
    for(int i=0;i<G.numVert;i++) {
        visited[i]=0;
    }
    cout<<getVertValue(G,v)<<" ";
    visited[v]=1;
    queue<int>Q;
    Q.push(v);
    while(!Q.empty()) {
        v1=Q.front();
        Q.pop();
        v2=firstNeighbor(G,v1);
        while(v2!=-1) {
            if(visited[v2]==0) {
                cout<<getVertValue(G,v2)<<" ";
                visited[v2]=1;
                Q.push(v2);
            }
            v2=nextNeighbor(G,v1,v2);
        }
    }
    cout<<endl;
    delete []visited;
}

int main() {
    ALgraph G;
    initGraph(G);
    int n,m;
    cin>>n>>m;
    createGraph(G,n,m);
    printGraph(G);
    dfs_traversal(G,0);
    bfs_traversal(G,0);
    return 0;
}
