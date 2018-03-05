#include <iostream>
using namespace std;

int main() {
    int s=0,m,n;
    cin>>n>>m;
    for(int i=2;i<=n;i++) {
        s=(s+m)%i;
    }
    cout<<s+1<<endl;
}
