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
      void iterativePreorder(Node* p);
      void iterativePreorder(){iterativePreorder(root); }
      void Inorder(Node* p);
      void Inorder(){ Inorder(root);}
      void iterativePostorder(Node* p);
      void iterativePostorder(){iterativePostorder(root);}
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
      stack<Node*> stk;
    while(p!=nullptr || !stk.empty()){
        if(p!=nullptr){
            stk.emplace(p);
            p=p->lchild;
        }else{
            p=stk.top();
            stk.pop();
            cout<<p->data<<", "<<flush;
            p=p->rchild;
        }
    }
    cout<< endl;
}

void Tree::iterativePreorder(Node *p){
    stack<Node*> stk;
    while(p!=nullptr || !stk.empty()){
        if(p!=nullptr){
            cout<<p->data<<", "<<flush;
            stk.emplace(p);
            p=p->lchild;
        }else{
            p=stk.top();
            stk.pop();
            p=p->rchild;
        }
    }
    cout<< endl;
}

void Tree::iterativePostorder(Node *p){
 stack<long int> stk;
 long int temp;
 while(p!=nullptr||!stk.empty()){
    if(p!=nullptr){
        stk.emplace((long int)p);
        p=p->lchild;
    }else{
        temp=stk.top();
        stk.pop();
        if(temp>0){
            stk.emplace(-temp);
            p=((Node*)temp)->rchild;
        }else{
            cout<<((Node*)(-1*temp))->data<<", "<<flush;
            p=nullptr;
        }
    }
 }
 cout<<endl;
}

int main(){
    Tree bt;

    bt.createTree();
    cout<<endl;

     cout<<"Inorder :"<<flush;
    bt.iterativePreorder();
    cout<<endl;

    cout<<"Inorder :"<<flush;
    bt.Inorder();
    cout<<endl;

     cout<<"Inorder :"<<flush;
    bt.iterativePostorder();
    cout<<endl;

    return 0;
}