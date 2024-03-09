#include <iostream>
#include <cmath>
using namespace std;

// struct Element {
//     int i;
//     int j;
//     int x;
// };

// struct Sparse {
//     int m;
//     int n;
//     int num;
//     Element *e;
// };

// void create(Sparse *s) {
//     cout << "Enter number of rows: ";
//     cin >> s->m;
//     cout << "Enter number of columns: ";
//     cin >> s->n;
//     cout << "Enter number of non-zero elements: ";
//     cin >> s->num;
//     s->e = new Element[s->num];
//     cout << "Enter non-zero elements (row, column, value):" << endl;
//     for (int i = 0; i < s->num; i++) {
//         cout << "Element " << i + 1 << ": ";
//         cin >> s->e[i].i >> s->e[i].j >> s->e[i].x;
//     }
// }

// void add(Sparse *s1, Sparse *s2) {
//     if (s1->m != s2->m || s1->n != s2->n) {
//         cout << "Matrices have different dimensions. Addition not possible." << endl;
//         return;
//     }

//     Sparse *sum = new Sparse;
//     sum->m = s1->m;
//     sum->n = s1->n;

//     // Initialize num to zero and dynamically allocate space for e
//     sum->num = 0;
//     sum->e = new Element[s1->num + s2->num];

//     int i = 0, j = 0, k = 0;
//     while (i < s1->num && j < s2->num) {
//         if (s1->e[i].i < s2->e[j].i || (s1->e[i].i == s2->e[j].i && s1->e[i].j < s2->e[j].j)) {
//             sum->e[k++] = s1->e[i++];
//         } else if (s1->e[i].i > s2->e[j].i || (s1->e[i].i == s2->e[j].i && s1->e[i].j > s2->e[j].j)) {
//             sum->e[k++] = s2->e[j++];
//         } else {
//             sum->e[k].i = s1->e[i].i;
//             sum->e[k].j = s1->e[i].j;
//             sum->e[k].x = s1->e[i].x + s2->e[j].x;
//             k++;
//             i++;
//             j++;
//         }
//     }

//     // Copy remaining elements from s1 or s2
//     while (i < s1->num) {
//         sum->e[k++] = s1->e[i++];
//     }
//     while (j < s2->num) {
//         sum->e[k++] = s2->e[j++];
//     }

//     // Update num to reflect the actual number of non-zero elements in sum
//     sum->num = k;

//     cout << "Resultant matrix after addition:" << endl;
//     for (int i = 0; i < sum->num; i++) {
//         cout << sum->e[i].i << " " << sum->e[i].j << " " << sum->e[i].x << endl;
//     }

//     delete[] sum->e; // Free memory allocated for sum->e
//     delete sum;      // Free memory allocated for sum
// }

// int main() {
//     Sparse s1, s2;
//     cout << "Creating sparse matrix 1:" << endl;
//     create(&s1);
//     cout << "Creating sparse matrix 2:" << endl;
//     create(&s2);
//     add(&s1, &s2);
//     return 0;
// }


//Answer 2
struct term {
    int coeff;
    int exp;
};

struct poly{
    int n;
    struct term *t;
};

int main(){
    struct poly  p;
    p.n=5;
    p.t=new term [p.n];
    for(int i=0; i<p.n; i++){
        cin>>p.t[i].coeff;
        cin>>p.t[i].exp;
    }
    int x;
    for (int j=0; j<p.n; j++){
        cout<<p.t[j].coeff*pow(x,p.t[j].exp)<<" +" ;
    }
}