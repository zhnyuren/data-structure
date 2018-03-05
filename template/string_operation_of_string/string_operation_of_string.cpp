#include <iostream>
#include <string>
using namespace std;

int mystrlen(char *s) {
    int i;
    for(i=0;s[i]!='\0';i++);
    return i;
}

int mystrcpy(char *s1,char *s2) {
    for(int i=0;i<mystrlen(s2);i++) {
        s1[i]=s2[i];
    }
    return 1;
}

int mystrncpy(char *s1,char *s2,int n) {
    if(n>mystrlen(s2)) n=mystrlen(s2);
    for(int i=0;i<n;i++) {
        s1[i]=s2[i];
    }
    return 1;
}

int mystrcat(char *s1,char *s2) {
    int i;
    int len1=mystrlen(s1);
    for(i=0;i<=mystrlen(s2);i++) {
        s1[len1+i]=s2[i];
    }
    return 1;
}

int mystrncat(char *s1,char *s2,int n) {
    int i;
    int len1=mystrlen(s1);
    if(n>mystrlen(s2)) n=mystrlen(s2);
    for(i=0;i<n;i++) {
        s1[len1+i]=s2[i];
    }
    s1[len1+i]='\0';
    return 1;
}

int mystrcmp(char *s1,char *s2) {
    int mini;
    if(mystrlen(s1)>=mystrlen(s2)) mini=mystrlen(s2);
    else mini=mystrlen(s1);
    for(int i=0;i<mini;i++) {
        if(s1[i]<s2[i]) return -1;
        if(s1[i]>s2[i]) return 1;
    }
    if(mystrlen(s1)>mystrlen(s2)) return 1;
    else if(mystrlen(s1)<mystrlen(s2)) return -1;
    else return 0;
}

int main() {
    char s1[100];
    char s2[100];
    cin>>s1;
    cin>>s2;
    string op;
    while(cin>>op) {
        if(op=="strlen1") {
            cout<<mystrlen(s1)<<endl;
        }
        else if(op=="strlen2") {
            cout<<mystrlen(s2)<<endl;
        }
        else if(op=="strcpy") {
            mystrcpy(s1,s2);
            cout<<s1<<" "<<s2<<endl;
        }
        else if(op=="strncpy") {
            int x;
            cin>>x;
            mystrncpy(s1,s2,x);
            cout<<s1<<" "<<s2<<endl;
        }
        else if(op=="strcat") {
            mystrcat(s1,s2);
            cout<<s1<<" "<<s2<<endl;
        }
        else if(op=="strncat") {
            int x;
            cin>>x;
            mystrncat(s1,s2,x);
            cout<<s1<<" "<<s2<<endl;
        }
        else if(op=="strcmp") {
            cout<<mystrcmp(s1,s2)<<endl;
        }
    }
}
