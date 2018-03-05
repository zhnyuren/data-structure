#include <stdio.h>

struct item
{
    int m;
    char a,b,c;
}tmp,rslt;

struct SqStack
{
    item data[100];
    int top;
}st;

void push(SqStack &st,item it)
{
    st.data[++st.top]=it;
}

int pop(SqStack &st,item &it)
{
    if(st.top==-1) return 0;
    else{
        it=st.data[st.top--];
        return 1;
    }
}

void hanoi(int n,char A,char B,char C)
{
    st.top=-1;
    tmp.m=n; tmp.a=A; tmp.b=B; tmp.c=C;
    push(st,tmp);
    while(st.top!=-1){
        pop(st,rslt);
        if(rslt.m==1){
            printf("%c -> %c\n",rslt.a,rslt.c);
        }
        else{
            tmp.m=rslt.m-1; tmp.a=rslt.b; tmp.b=rslt.a; tmp.c=rslt.c; push(st,tmp);
            tmp.m=1; tmp.a=rslt.a; tmp.b=rslt.b; tmp.c=rslt.c; push(st,tmp);
            tmp.m=rslt.m-1; tmp.a=rslt.a; tmp.b=rslt.c; tmp.c=rslt.b; push(st,tmp);
        }
    }
}

int main()
{
    int n;
    while(~scanf("%d",&n)){
        hanoi(n,'A','B','C');
        printf("Finished!\n");
    }
}
