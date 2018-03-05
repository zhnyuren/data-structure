#include <iostream>
using namespace std;

void swap2(int*,int*);

int main()
{
    int a=1,b=2;
    swap2(&a,&b);
    cout<<a<<" "<<b<<endl;
    return 0;
}

void swap2(int* p1,int* p2)
{
    int temp=*p1;
    *p1=*p2;
    *p2=temp;
}
