#include <iostream>
#include <string>
using namespace std;
struct charStack
{
    char *sym;
    int top=-1;
}cst;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cst.top=-1;//要记得初始化top！！！
        string exp;
        cin>>exp;
        int n=exp.size();
        cst.sym=new char[n+1];//留出'\0'的位置！！
        bool flag=true;
        for(int i=0;i<n;i++){
            if(exp[i]=='('||exp[i]=='['||exp[i]=='{'){
                //压入栈中
                cst.sym[++cst.top]=exp[i];
            }
            else if(exp[i]==')'||exp[i]==']'||exp[i]=='}'){
                if(cst.top==-1){
                    flag=false;
                    break;
                }
                else{
                    if(cst.sym[cst.top]=='('&&exp[i]==')'){
                        cst.top--;
                    }
                    else if(cst.sym[cst.top]=='['&&exp[i]==']'){
                        cst.top--;
                    }
                    else if(cst.sym[cst.top]=='{'&&exp[i]=='}'){
                        cst.top--;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
            }
        }
        if(!flag){
            cout<<"NO\n";
        }
        else{
            if(cst.top==-1){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
}

