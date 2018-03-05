#include <iostream>
using namespace std;

typedef char DataType;

typedef struct _BTnode {
    DataType data;
    struct _BTnode *lchild,*rchild;
}BTnode, *BinTree;

void createBinTreePre(BTnode *&root) {
    DataType item;
    cin>>item;
    if(item==';') return;
    if(item!='#') {
        root=new BTnode;
        root->data=item;
        createBinTreePre(root->lchild);
        createBinTreePre(root->rchild);
    }
    else root=nullptr;
}

void createBinTreeIn(BTnode *&root) {
    DataType item;
    cin>>item;
    if(item==';') return;
    if(item!='#') {
        root=new BTnode;
        createBinTreeIn(root->lchild);
        root->data=item;
        createBinTreeIn(root->rchild);
    }
    else root=nullptr;
}

void createBinTreePost(BTnode *&root) {
    DataType item;
    cin>>item;
    if(item==';') return;
    if(item!='#') {
        root=new BTnode;
        createBinTreePost(root->lchild);
        createBinTreePost(root->rchild);
        root->data=item;
    }
    else root=nullptr;
}

void PreOrder(BTnode *root) {
    if(root!=nullptr) {
        cout<<root->data;
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

void InOrder(BTnode *root) {
    if(root!=nullptr) {
        InOrder(root->lchild);
        cout<<root->data;
        InOrder(root->rchild);
    }
}

void PostOrder(BTnode *root) {
    if(root!=nullptr) {
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        cout<<root->data;
    }
}

int height(BTnode *root) {
    if(root==nullptr) return 0;
    else {
        int i=height(root->lchild);
        int j=height(root->rchild);
        if(i<j) return j+1;
        else return i+1;
    }
}

void clearBinTree(BTnode *&root) {
    if(root!=nullptr) {
        clearBinTree(root->lchild);
        clearBinTree(root->rchild);
        delete root; root=nullptr;
    }
}

void printGeneList(BTnode *root) {
    if(root!=nullptr) {
        cout<<root->data;
        if(root->lchild!=nullptr || root->rchild!=nullptr) {
            cout<<'(';
            printGeneList(root->lchild);
            if(root->rchild!=nullptr) {
                cout<<',';
                printGeneList(root->rchild);
            }
            cout<<')';
        }
    }
}

int equalTwoTrees(BTnode *root1,BTnode *root2) {
    if(root1==nullptr && root2==nullptr) return 1;
    if(root1==nullptr || root2==nullptr) return 0;
    if(root1->data!=root2->data) return 0;
    if(!equalTwoTrees(root1->lchild,root2->lchild)) return 0;
    if(!equalTwoTrees(root1->rchild,root2->rchild)) return 0;
    return 1;
}

int likeTwoTrees(BTnode *root1,BTnode *root2) {
    int l1,l2;
    if(root1==nullptr && root2==nullptr) return 1;
    if((root1!=nullptr && root2==nullptr) || (root1==nullptr && root2!=nullptr)) return 0;
    if(!likeTwoTrees(root1->lchild,root2->lchild)) return 0;
    if(!likeTwoTrees(root1->rchild,root2->rchild)) return 0;
    return 1;
}

BTnode* findParent(BTnode *root,BTnode *p) {
    if(root==p) return nullptr;
    if(root!=nullptr) {
        if(root->lchild==p || root->rchild==p) {
            return root;
        }
        findParent(root->lchild);
        findParent(root->rchild);
    }
}



int main() {
    BTnode *root;

    createBinTreePre(root);

    cout<<"pre order output: ";
    PreOrder(root);
    cout<<endl;

    cout<<"in order output: ";
    InOrder(root);
    cout<<endl;

    cout<<"post order output: ";
    PostOrder(root);
    cout<<endl;

    cout<<"height of the tree: "<<height(root)<<endl;

    cout<<"generalized list: ";
    printGeneList(root);
    cout<<endl;

    BTnode *root1,*root2;
    createBinTreePre(root1);
    createBinTreePre(root2);
    if(equalTwoTrees(root1,root2)) cout<<"YES\n";
    else cout<<"NO\n";

    BTnode *root3,*root4;
    createBinTreePre(root3);
    createBinTreePre(root4);
    if(likeTwoTrees(root3,root4)) cout<<"YES\n";
    else cout<<"NO\n";
}
