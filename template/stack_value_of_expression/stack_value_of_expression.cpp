#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

struct CharStack
{
    char data[110];
    int top=-1;
}OPTR;

struct IntStack
{
    int data[110];
    int top=-1;
}numSt;

int inits(CharStack &st)
{
    memset(st.data,0,110);
    st.top==-1;
    return 1;
}

int pushChar(CharStack &st,char x)
{
    st.data[++st.top]=x;
    return 1;
}

int popChar(CharStack &st,char &x)
{
    if(st.top==-1) return 0;
    else{
        x=st.data[st.top--];
        return 1;
    }
}

int inits(IntStack &st)
{
    memset(st.data,0,110);
    st.top==-1;
    return 1;
}

int pushInt(IntStack &st,int x)
{
    st.data[++st.top]=x;
    return 1;
}

int popInt(IntStack &st,int &x)
{
    if(st.top==-1) return 0;
    else{
        x=st.data[st.top--];
        return 1;
    }
}

int calulate(char ch,int leftnum,int rightnum)
{
    switch(ch)
    {
    case '+':
        return leftnum+rightnum;
    case '-':
        return leftnum-rightnum;
    case'*' :
        return leftnum*rightnum;
    case '/':
        return leftnum/rightnum;
    default:
        return 0;
    }
}

int priority(char ch1,char ch2)
{
    int isp,icp;
    if('+'==ch1||'-'==ch1) isp = 3;
    else if('*'==ch1||'/'==ch1)isp = 5;
    else if('('==ch1) isp = 1;
    else if(')'==ch1) isp = 7;
    else if('#'==ch1) isp = 0;

    if('+'==ch2||'-'==ch2)icp = 2;
    else if('*'==ch2||'/'==ch2)icp = 4;
    else if('('==ch2) icp = 6;
    else if(')'==ch2) icp = 1;
    else if('#'==ch2) icp = 0;

    if(isp>icp) return 1;
    else if(isp==icp) return 0;
    else return -1;
}

int main()
{
    string infixExp;
    while(cin>>infixExp){
        for(int i=0;i<infixExp.size();i++){
            if((i==0||(i!=0&&infixExp[i-1]=='('))&&infixExp[i]=='-'){
                infixExp.insert(i,"0");
            }
        }
        infixExp.append(1,'#');
        inits(numSt);
        inits(OPTR);
        int cnt=-1;
        int tag,checkThePrior,opnumber;
        pushChar(OPTR,'#');//put the '#' into the stack
        char symbol[]="*/()#+-";
        while(1){
            tag=cnt+1;
            cnt=infixExp.find_first_of(symbol,tag);
            if(string::npos==cnt)
                break;
            else if(cnt!=tag){
                string tmpStr(infixExp,tag,cnt-tag);
                opnumber=atof(tmpStr.c_str());
                pushInt(numSt,opnumber);
            }
            checkThePrior=priority(OPTR.data[OPTR.top],infixExp[cnt]);
            if(checkThePrior==-1){
                pushChar(OPTR,infixExp[cnt]);
            }
            else if(checkThePrior==0){
                char opPop;
                popChar(OPTR,opPop);
            }
            else if(checkThePrior==1){
                int numPop,leftnum,rightnum;
                char opPop;
                leftnum=numSt.data[numSt.top];
                popInt(numSt,numPop);
                rightnum=numSt.data[numSt.top];
                popInt(numSt,numPop);
                leftnum=calulate(OPTR.data[OPTR.top],rightnum,leftnum);
                pushInt(numSt,leftnum);
                popChar(OPTR,opPop);
                cnt--;
            }
        }
        cout<<numSt.data[numSt.top]<<"\n";
    }
}

