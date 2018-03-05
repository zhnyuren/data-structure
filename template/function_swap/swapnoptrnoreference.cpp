#include <iostream>
using namespace std;
void swap1(int,int);
int main()
{
    int a=1,b=2;
    swap1(a,b);
    return 0;
}

void swap1(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
    cout<<a<<" "<<b<<endl;
}
