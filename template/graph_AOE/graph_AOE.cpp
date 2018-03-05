#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
#define MAXVERT 30
#define MAXEDGE 100
using namespace std;

/*
9 11
0 1 2 3 4 5 6 7 8
0 1 6
0 2 4
0 3 5
1 4 1
2 4 1
3 5 2
4 6 9
4 7 7
5 7 4
6 8 2
7 8 4
*/

typedef int vtype;//typedef int vtype;
typedef int wtype;

struct edgeNode {
    wtype cost;
    int dest;
    edgeNode *next;
};

struct vertNode {
    vtype data;
    edgeNode *first;
};

struct ALgraph {
    vertNode *vertList;
    int nVert,nEdge;
};

struct criticalNode {
    int head,tail;
    wtype weight;
};

criticalNode path[MAXEDGE];
int cntPath=0;

void initGraph(ALgraph &G) {
    G.nEdge=0;
    G.nVert=0;
    G.vertList=new vertNode[MAXVERT];
    for(int i=0;i<MAXVERT;i++) {
        G.vertList[i].first=nullptr;
    }
}

int getVertPos(ALgraph &G,vtype x) {
    for(int i=0;i<MAXVERT;i++) {
        if(G.vertList[i].data==x) {
            return i;
        }
    }
    return -1;
}

vtype getVertValue(ALgraph &G,int pos) {
    if(pos>=0 && pos<G.nVert) {
        return G.vertList[pos].data;
    }
    return 0;//return 'null';
}

wtype getVertWeight(ALgraph &G,int v1,int v2) {
    if(v1>=0 && v1<G.nVert && v2>=0 && v2<G.nVert) {
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
    if(v>=0 && v<G.nVert) {
        edgeNode *p=G.vertList[v].first;
        if(p!=nullptr) {
            return p->dest;
        }
    }
    return -1;
}

int nextNeighbor(ALgraph &G,int v1,int v2) {
    if(v1>=0 && v1<G.nVert && v2>=0 && v2<G.nVert) {
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
    G.nVert=nVert;
    G.nEdge=mEdge;
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
//                r=new edgeNode;//if it is a directed graph,
//                r->dest=j;//comment these code
//                r->cost=weight;//if it is a directed graph,
//                r->next=G.vertList[k].first;//comment these code
//                G.vertList[k].first=r;//if it is a directed graph, comment these code
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

void criticalPath(ALgraph &G) {
    cntPath=0;
    wtype w,ae,al;
    criticalNode tmp;
    int n=G.nVert;
    int *ve=new int[n];
    int *vl=new int[n];
    for(int i=0;i<n;i++) ve[i]=0;
    for(int i=0;i<n;i++) {
        for(int j=firstNeighbor(G,i);j!=-1;j=nextNeighbor(G,i,j)) {
            w=getVertWeight(G,i,j);
            if(ve[i]+w>ve[j]) ve[j]=ve[i]+w;
        }
    }
    for(int i=0;i<n;i++) vl[i]=ve[i];
    for(int i=n-2;i>0;i--) {
        for(int j=firstNeighbor(G,i);j!=-1;j=nextNeighbor(G,i,j)) {
            w=getVertWeight(G,i,j);
            if(vl[j]-w<vl[i]) vl[i]=vl[j]-w;
        }
    }
    cntPath=0;
    for(int i=0;i<n;i++) {
        for(int j=firstNeighbor(G,i);j!=-1;j=nextNeighbor(G,i,j)) {
            w=getVertWeight(G,i,j);
            ae=ve[i];
            al=vl[j]-w;
            if(ae==al) {
                tmp.head=i;
                tmp.tail=j;
                tmp.weight=w;
                path[cntPath++]=tmp;
            }
        }
    }
}

void printAOE(ALgraph &G) {
    for(int i=0;i<cntPath;i++) printf("%d ",path[i].head);
}

int main() {
    int n,m;
    while(~scanf("%d%d",&n,&m)) {
        ALgraph G;
        initGraph(G);
        createGraph(G,n,m);
        criticalPath(G);
        printAOE(G);
    }
    return 0;
}
