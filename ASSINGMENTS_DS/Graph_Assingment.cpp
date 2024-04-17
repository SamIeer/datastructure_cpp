#include <iostream>
#define I 32767  //INFINITY
#define V 7 // # of vertices in graph
#define E 9 // # of edges in graph

using namespace std;

void PrintMST(int T[][V-1], int A[][E]){
    cout << "\nMinimum cost spanning Tree Edges\n" << endl;
    for (int i {0}; i<V-1; i++){
        cout << "[" << T[0][i] << "]----[" << T[1][i] << "]" << endl;
    }
    cout << endl;
}

//set operations: UNion and Find
void Union(int u,int v,int s[]){
    if (s[u] < s[v]){
        s[u] += s[v];
        s[v] = u;
    }else {
        s[v] += s[u];
        s[u] = v;
    }
}

int Find(int u, int s[]){
    int x = u;
    int v = 0;

    while (s[x] > 0){
        x = s[x];
    }

    while(u != x){
        v = s[u];
        s[u] = x;
        u = v;
    }
    return x;
}

void KruskalsMCST(int A[3][9]){
    int T[2][V-1];    //solution array
    int track[E] {0}; //Track edges that are included in the solution
    int set[V+1] = {-1,-1,-1,-1,-1,-1,-1,-1 }; // array for finding cycle

    int i {0};
    while (i < V-1){
        int min =I;
        int u {0};
        int v {0};
        int k {0};

        //Find a minumum cost edge from full graph 
        for (int j {0}; j<E; j++){
            if (track[j] == 0 && A[2][j] < min){
                min = A[2][j];
                u = A[2][j];
                v = A[1][j];
                k = j;
            }
        }

        //check if the selected min cost edge (u ,v) forming a cycle or not
        if(Find(u , set) != Find(v, set)){
            T[0][i] = u;
            T[1][i] = v;
            
            //perform union
            Union(Find(u,set), Find(v, set), set);
            i++;
        }
        track[k] = 1; //k edge is considered
    }
    PrintMST(T,A);
}

int main(){
    int edges[3][9] = {
          {1,1,2,2,3,4,4,5,5},
          {2,6,3,7,4,5,7,6,7},
          {25,5,12,10,8,16,14,20,18}
    };
    KruskalsMCST(edges);

    return 0;
}