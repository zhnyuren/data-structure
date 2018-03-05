#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>
#define MAXVERT 30
using namespace std;

/*
9 11
1 2 3 4 5 6 7 8 9
1 8 24
1 3 46
2 3 15
2 5 67
2 4 53
8 9 31
3 4 54
9 7 67
4 7 45
4 6 67
5 6 23
*/

int cntTopo=0;
int topoArr[MAXVERT];

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

bool topoSort(ALgraph &G) {
    stack<int> S;
    int n=G.nVert;
    int indegree[n];
    memset(indegree,0,sizeof(indegree));
    memset(topoArr,0,sizeof(topoArr));
    for(int i=0;i<n;i++) {
        for(int j=firstNeighbor(G,i);j!=-1;j=nextNeighbor(G,i,j)) {
            indegree[j]++;
        }
    }
    for(int i=0;i<n;i++) {
        if(!indegree[i]) S.push(i);
    }
    cntTopo=0;
    for(int i=0;i<n;i++) {
        if(!S.empty()) {
            int out=S.top();
            S.pop();
            topoArr[cntTopo++]=out;
            for(int j=firstNeighbor(G,out);j!=-1;j=nextNeighbor(G,out,j)) {
                if(--indegree[j]==0) S.push(j);
            }
        }
        else return false;
    }
    return true;
}

void printAOV(ALgraph G) {
    for(int i=0;i<cntTopo;i++) {
        printf("%d ",getVertValue(G,topoArr[i]));
    }
    printf("\n");
}

int main() {
    int n,m;
    while(~scanf("%d%d",&n,&m)) {
        ALgraph G;
        initGraph(G);
        createGraph(G,n,m);
        topoSort(G);
        printAOV(G);
    }
    return 0;
}
