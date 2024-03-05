#include <iostream>
using namespace std;

struct Element{
    int i ; int j ; int x;
};

struct Sparse{
    int m ; int n ; int num 
     ; struct Element *e ;
};

void create(struct Sparse *s){
    s->m = 10;
    s->n = 10;
    s->num = 5;
    s->e = new Element[s->num];
    for(int i=0; i<s->num; i++){
        cin>>s->e[i].i;
        cin>>s->e[i].j;
        cin>>s->e[i].x;
    }
}

void add(struct Sparse *s1,struct Sparse *s2){
    if(s1->m!=s2->m || s1->n!=s2->n){
      return 0;
    }
    Sparse *sum;
    sum = new Sparse;
    sum->m = s1->m;
    sum->n = s1->n;
    sum->e = new Element[s1->num + s2->num];
     int i=0 , j=0 , k=0;
    while(i<s1->num &&  j<s2->num){
         if(s1->e[i].i < s2->e[j].i){
            sum->e[k++] = s1->e[i++];
         }
         else if(s1->e[i].i < s1-> e[j].i){
            sum->e[k++] = s2->e[i++];
         }
         else{
            if(s1->e[i].j<s2->e[j].j){sum->e[k++] = s1->e[i++]; }

            else if(s1->e[i].j < s1->e[j].j){ sum->e[k++] = s2->e[i++]; }

            else {sum->e[k++] = s1->e[i++];
            sum->e[k++].x = s2->e[j++].x;
            }
         }
    }
}

void main(){
    struct Sparse s1 , s2;
    add(&s1 , &s2);

}