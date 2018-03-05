#include <iostream>
#include <string>
#define MAX_SIZE 100
using namespace std;

typedef int SDataType;

typedef struct _sqstack {
    SDataType data[MAX_SIZE];
    int top;
}sqstack;

void initStack(sqstack &s) {
    s.top=-1;
}

int push(sqstack &s,SDataType x) {
    if(s.top==MAX_SIZE-1) return 0;
    s.data[++s.top]=x;
    return 1;
}

int pop(sqstack &s,SDataType &x) {
    if(s.top==-1) return 0;
    x=s.data[s.top--];
    return 1;
}

int getLength(sqstack s) {
    return s.top+1;
}

int getTop(sqstack s,SDataType &x) {
    if(s.top==-1) return 0;
    x=s.data[s.top];
    return 1;
}

int isEmpty(sqstack s) {
    if(s.top==-1) return 1;
    else return 0;
}

int isFull(sqstack s) {
    if(s.top==MAX_SIZE) return 1;
    else return 0;
}

int main() {
    string op;
    sqstack s;
    initStack(s);
    while(cin>>op) {
        if(op=="push") {
            SDataType x;
            cin>>x;
            if(!push(s,x)) cout<<"stack is full\n";
        }
        else if(op=="pop") {
            SDataType x;
            if(!pop(s,x)) cout<<"stack is empty\n";
            else cout<<"pop "<<x<<endl;
        }
        else if(op=="cnt") {
            cout<<getLength(s)<<endl;
        }
        else if(op=="gettop") {
            SDataType x;
            if(!getTop(s,x)) cout<<"stack is empty\n";
            else cout<<x<<endl;
        }
    }
}
