#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node{
    public:
     Node*lchild;
     int data;
     Node*rchild;
     Node(){};
     Node(int data);
};

Node::Node(int data){
    lchild=nullptr;
    this->data=data;
    rchild=nullptr;
}

class Tree{
    private:
     Node* root;
    public:
     Tree();
     Node* generateFromTraversal(int *inorder,int *preorder,int instart,int inEnd);
     int leafNodeCount(Node* p);
};
Tree::Tree(){
    root = nullptr;
}

int searchInorder(int inArray[],int instart,int inEnd,int data){
    for(int i=instart;i<=inEnd;i++){
        if(inArray[i]==data){
            return i;
        }
    }
    return -1;
}

Node* Tree::generateFromTraversal(int *inorder,int *preorder,int instart,int inEnd){
    static int preIndex=0;
    if(instart > inEnd){
        return nullptr;
    }
    Node* node=new Node(preorder[preIndex++]);

    if(instart==inEnd){
        return node;
    }
    int splitIndex=searchInorder(inorder,instart,inEnd,node->data);
    node->lchild=generateFromTraversal(inorder,preorder,instart,splitIndex-1);
    node->rchild=generateFromTraversal(inorder,preorder,splitIndex+1,inEnd);

    return node;
}

int Tree::leafNodeCount(Node* p){
    int x; int y;
    if(p!=nullptr){
        x=leafNodeCount(p->lchild);
        y=leafNodeCount(p->rchild);
        if(p->lchild == nullptr && p->rchild == nullptr){
            return x+y+1;
        }else{
            return x+y;
        }
    }
    return 0;
}

int main(){
    Tree bt;
    int preorder[]={8,3,12,4,9,7,10,6,2};
    int inorder[]={12,9,4,7,3,8,10,5,2,6};
    int size=sizeof(inorder)/sizeof(inorder[0]);
    Node* T= bt.generateFromTraversal(inorder,preorder,0,size-1);
    cout<<"# of leaf nodes:"<<bt.leafNodeCount(T)<<endl;
    return 0;
}


