#include <iostream>
#include <string>
#define MAX_SIZE 100
using namespace std;

typedef int DataType;

int shuffle[MAX_SIZE];
string output[2*MAX_SIZE];

typedef struct _sqstack {
    DataType data[MAX_SIZE];
    int top;
}sqstack;

void initStack(sqstack &s) {
    s.top=-1;
}

int push(sqstack &s,DataType x) {
    if(s.top==MAX_SIZE-1) return 0;
    s.data[++s.top]=x;
    return 1;
}

int pop(sqstack &s,DataType &x) {
    if(s.top==-1) return 0;
    x=s.data[s.top--];
    return 1;
}

int getLength(sqstack s) {
    return s.top+1;
}

int getTop(sqstack s,DataType &x) {
    if(s.top==-1) return 0;
    x=s.data[s.top];
    return 1;
}

int main() {
    int n;
    while(cin>>n) {
        int cnt=0;
        sqstack s;
        initStack(s);
        for(int i=0;i<n;i++) {
            cin>>shuffle[i];
        }
        int a=1;
        int flag=0;
        for(int i=0;i<n;i++) {
            while(s.top==-1 || s.data[s.top]<shuffle[i]) {
                push(s,a++);
                output[cnt++]="push";
            }
            if(s.data[s.top]==shuffle[i]) {
                DataType x;
                pop(s,x);
                output[cnt++]="pop";
            }
            else {
                flag=1;
                break;
            }
        }
        if(flag) {
            cout<<"No\n";
        }
        else {
            for(int i=0;i<2*n;i++) {
                cout<<output[i]<<endl;
            }
        }
    }
}
