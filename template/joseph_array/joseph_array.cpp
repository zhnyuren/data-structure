#include <iostream>
using namespace std;
int main()
{
    int s[101], i,a=1,n,m,cnt=0;
    cout<<"The number of monkey is: "<<endl;
    cin>>n;
    cout<<"Input a number, m: "<<endl;
    cin>>m;
    for(i=1;i<=n;i++) s[i]=1;
    for(i=1;i<=n-1;i++) {
        cnt=0;
        while(cnt!=m-1) {
            if(s[a]==1) cnt++;
            a++;
            if(a==n+1) a=1;
        }
        if(s[a]==0) {
            a++;
            if(a==n+1) a=1;
            while(s[a]==0) {
                a++;
                if(a==n+1) a=1;
            }
        }
        cout<<"The deleted one is:"<<a<<endl;
        s[a]=0;
    }
    for (i=1;i<=n;i++) {
        if (s[i]!=0) {
            cout<<"The No. "<<i<<" monkey is the king."<<endl;
            break;
        }
    }
}

