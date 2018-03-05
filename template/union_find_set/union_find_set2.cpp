#include <iostream>
#include <algorithm>
#define MAXE 600006
#define MAXV 10004
using namespace std;

struct edge {
    int v1,v2,weight;
};

edge myEdge[MAXE];
int father[MAXV];
int nVert,nEdge;

int findf(int item) {
    return father[item]==item?item:father[item]=findf(father[item]);
}

bool cmp(const edge &a,const edge &b) {
    return a.weight<b.weight;
}

int kruskal() {
    int RES=0;
    for(int i=0;i<nVert;i++) father[i]=i;
    sort(myEdge,myEdge+nEdge,cmp);
    for(int i=0;i<nEdge;i++) {
        int a=findf(myEdge[i].v1);
        int b=findf(myEdge[i].v2);
        if(a!=b) {
            RES+=myEdge[i].weight;
            father[a]=b;
        }
    }
    return RES;
}

int main() {
    while(cin>>nVert>>nEdge) {
        for(int i=0;i<nEdge;i++) cin>>myEdge[i].v1>>myEdge[i].v2>>myEdge[i].weight;
        cout<<kruskal()<<"\n";
    }
}
