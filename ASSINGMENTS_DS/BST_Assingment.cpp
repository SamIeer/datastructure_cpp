#include <iostream>
#include <stack>
using namespace std;

class Node{
    public:
     Node *lchild;
     int data ;
     Node *rchild;
};

class BST{
    private:
      Node *root;
    public:
      BST(){
         root = nullptr;
      }
      void insert(int key);
      int GreatersumTree(Node *p, int sum);
      void Inorder(Node *p );
       Node* getroot(){
        return root;
     }
};

void BST::insert(int key){
    Node* t = root;
    Node* p;
    Node* r;
    if(root == nullptr){
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }
    while(t!=nullptr){
        r = t;
        if(key < t->data){
            t = t->lchild; }

        else if(key > t->data){
            t = t->rchild; }

        else{
            return; }
        }

        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        if(key < r->data){
            r->lchild = p;
        }
        else{
            r->rchild = p;
        }
}

void BST::Inorder(Node *p){
    if(p){
    Inorder(p->lchild);
    cout<<p->data<<" ";
    Inorder(p->rchild);
    }
}

int BST::GreatersumTree(Node *T , int sum){
    if(T == nullptr)
        return sum;
    
    sum = GreatersumTree(T->rchild , sum); //traversing the right sub tree
    
    //updating the value of Node
    sum +=T->data;
    T->data = sum;

    return GreatersumTree(T->lchild, sum); //traversing the left subtree
}

int main(){
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);

    cout << "BST :";
    bst.Inorder(bst.getroot());
    cout<<endl;

    bst.GreatersumTree(bst.getroot(),0);

    cout<<"greater sum Tree :"<<endl;
    bst.Inorder(bst.getroot());
}