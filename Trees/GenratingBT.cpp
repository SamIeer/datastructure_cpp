#include <iostream>
#include <queue>
#include <stack>

using namespace std;
class Node{
    public:
     Node*lchild;
     int data;
     Node *rchild;
     Node() {};
     Node(int data);
};

Node::Node(int data){
    lchild=nullptr;
    this->data=data;
    rchild=nullptr;
}

class Tree{
    private: 
     Node*root;
    public:
     Tree();
     Node* generateFromTraversal(int *inorder,int *preorder,int instart,int inEnd);
};

Tree::Tree(){
    root=nullptr;
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

int main(){
    Tree bt;
    int preorder[]={4,7,9,6,3,2,5,8,1};
    int inorder[]={7,6,9,3,4,5,8,2,1};
    Node* T=bt.generateFromTraversal(inorder,preorder,0,sizeof(inorder)/sizeof(inorder[0])-1);
    cout<<T;
    return 0;

}