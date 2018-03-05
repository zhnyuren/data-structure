#include <iostream>
using namespace std;

void swap3(int&,int&);

int main()
{
    int a=1,b=2;
    swap3(a,b);
    cout<<a<<" "<<b<<endl;
    return 0;
}

void swap3(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
