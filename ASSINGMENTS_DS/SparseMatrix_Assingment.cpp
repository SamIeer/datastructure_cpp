#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

struct Element {
    int i;
    int j;
    int x;
};

struct Sparse {
    int m;
    int n;
    int num;
    Element *e;
};

void create(Sparse *s) {
    cout << "Enter number of rows: ";
    cin >> s->m;
    cout << "Enter number of columns: ";
    cin >> s->n;
    cout << "Enter number of non-zero elements: ";
    cin >> s->num;
    s->e = new Element[s->num];
    cout << "Enter non-zero elements (row, column, value):" << endl;
    for (int i = 0; i < s->num; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> s->e[i].i >> s->e[i].j >> s->e[i].x;
    }
}

void add(Sparse *s1, Sparse *s2) {
    if (s1->m != s2->m || s1->n != s2->n) {
        cout << "Matrices have different dimensions. Addition not possible." << endl;
        return;
    }

    Sparse *sum = new Sparse;
    sum->m = s1->m;
    sum->n = s1->n;

    // Initialize num to zero and dynamically allocate space for e
    sum->num = 0;
    sum->e = new Element[s1->num + s2->num];

    int i = 0, j = 0, k = 0;
    while (i < s1->num && j < s2->num) {
        if (s1->e[i].i < s2->e[j].i || (s1->e[i].i == s2->e[j].i && s1->e[i].j < s2->e[j].j)) {
            sum->e[k++] = s1->e[i++];
        } else if (s1->e[i].i > s2->e[j].i || (s1->e[i].i == s2->e[j].i && s1->e[i].j > s2->e[j].j)) {
            sum->e[k++] = s2->e[j++];
        } else {
            sum->e[k].i = s1->e[i].i;
            sum->e[k].j = s1->e[i].j;
            sum->e[k].x = s1->e[i].x + s2->e[j].x;
            k++;
            i++;
            j++;
        }
    }

    // Copy remaining elements from s1 or s2
    while (i < s1->num) {
        sum->e[k++] = s1->e[i++];
    }
    while (j < s2->num) {
        sum->e[k++] = s2->e[j++];
    }

    // Update num to reflect the actual number of non-zero elements in sum
    sum->num = k;

    cout << "Resultant matrix after addition:" << endl;
    for (int i = 0; i < sum->num; i++) {
        cout << sum->e[i].i << " " << sum->e[i].j << " " << sum->e[i].x << endl;
    }

    delete[] sum->e; // Free memory allocated for sum->e
    delete sum;      // Free memory allocated for sum
}

int main() {
    Sparse s1, s2;
    cout << "Creating sparse matrix 1:" << endl;
    create(&s1);
    cout << "Creating sparse matrix 2:" << endl;
    create(&s2);
    add(&s1, &s2);
    return 0;
}



//Answer 2
#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

void create(Node **poly) {
    struct Node *t,*last=NULL;
    int num, i;
    cout << "Enter number of terms: ";
    cin >> num;
    cout << "Enter each term's value and coefficient: " << endl;
    for(i = 0; i < num; i++) {
        t = new Node;
        cin >> t->coeff >> t->exp;
        t->next = NULL;
        if(*poly == NULL) {
            *poly = last = t;
        } else {
            last->next = t;
            last = t;
        }
    }
}

void Display(struct Node *p) {
    while(p) {
        cout << p->coeff << "x^" << p->exp;
        p = p->next;
        if(p) cout << " + ";
    }
    cout << endl;
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;
    Node* last = nullptr;

    while (poly1 && poly2) {
        Node* temp = new Node;
        temp->next = nullptr;

        if (poly1->exp > poly2->exp) {
            temp->coeff = poly1->coeff;
            temp->exp = poly1->exp;
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            temp->coeff = poly2->coeff;
            temp->exp = poly2->exp;
            poly2 = poly2->next;
        } else {
            temp->coeff = poly1->coeff + poly2->coeff;
            temp->exp = poly1->exp;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (!result) {
            result = last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }

    while (poly1) {
        Node* temp = new Node;
        temp->coeff = poly1->coeff;
        temp->exp = poly1->exp;
        temp->next = nullptr;

        last->next = temp;
        last = temp;
        poly1 = poly1->next;
    }

    while (poly2) {
        Node* temp = new Node;
        temp->coeff = poly2->coeff;
        temp->exp = poly2->exp;
        temp->next = nullptr;

        last->next = temp;
        last = temp;
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    struct Node *poly1 = nullptr, *poly2 = nullptr;
    
    cout << "Creating polynomial 1:" << endl;
    create(&poly1);
    cout << "Creating polynomial 2:" << endl;
    create(&poly2);
    
    cout << "Polynomial 1: ";
    Display(poly1);
    cout << "Polynomial 2: ";
    Display(poly2);

    Node* sum = addPolynomials(poly1, poly2);
    cout << "Sum of polynomials: ";
    Display(sum);

    // Free memory allocated for the sum polynomial
    Node* temp;
    while (sum) {
        temp = sum;
        sum = sum->next;
        delete temp;
    }

    return 0;
}



