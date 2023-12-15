#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{
    public:
     Node* lchild;
    int data;
    Node* rchild;
};

class Tree{
    private: 
     Node*root;
     public:
      Tree();
      void createTree();
      void Inorder(Node* p);
      void Inorder(){
        Inorder(root);
      }
};

Tree::Tree(){
    root = nullptr;
}

void Tree::createTree(){
    Node*p;
    Node*t;
    int x;
    queue<Node*> q;

    root = new Node;
    cout<<"Enter root Data: "<<flush;
    cin>>x;
    root->data=x;
    root->lchild=nullptr;
    root->rchild=nullptr;
    q.emplace(root);

    while(! q.empty()){
        p=q.front();
        q.pop();

        cout<<"Enter the left child data of "<<p->data<<" :"<<flush;
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=nullptr;
            t->rchild=nullptr;
            p->lchild=t;
            q.emplace(t);
        }
        cout<<"Enter right Child data of "<<p->data<<" :"<<flush;
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data = x;
            t->lchild=nullptr;
            t->rchild=nullptr;
            p->rchild=t;
            q.emplace(t);
        }
    }
}

void Tree::Inorder(Node* p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<","<<flush;
        Inorder((p->rchild));
    }
}

int main(){
    Tree bt;

    bt.createTree();
    cout<<endl;
    cout<<"Inorder :"<<flush;
    bt.Inorder();
    cout<<endl;

    return 0;
}
