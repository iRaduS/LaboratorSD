#include <bits/stdc++.h>
using namespace std;

// structura este luata din PDF-ul cu suport-ul de laboartor
struct Node {
    int Grade, Coef;
    Node *Next;
} *P, *Q;

void createNode(Node *&head, int grade, int coef) {
    Node *node = new Node;
    node->Grade = grade, node->Coef = coef;

    if (head == NULL) { // nu exista inceputul listei
        head = node;
    } else { // inseram in fata
        node->Next = head;
        head = node;
    }
}

/*
 * sign*abs(Coef)*X^(Grade)
 * sign -> + -> doar daca trece de elm. cu gradul cel mai mare / -
 * daca coef == 0 -> nu se afiseaza
 * daca grade == 0 -> nu se afiseaza ala
 */
void multiplyWithScalar(Node *head, int scalar) {
    while (head != NULL) {
        head->Coef *= scalar;
        head = head->Next;
    }
}

void showPolinom(Node *head) {
    int nodes = 0;
    while (head != NULL) {
        if (nodes == 0) {
            if (head->Grade > 0) {
                cout << ((head->Coef != 0 && head->Coef != 1 && head->Coef != -1) ? (to_string(head->Coef))
                                                                                  : (head->Coef == -1) ? "-" : "");
                if (head->Coef != 0) {
                    cout << (head->Grade != 0 ? (head->Grade != 1 ? ("X^" + to_string(head->Grade)) : "X") : "");
                }
            } else {
                cout << head->Coef;
            }
        } else {
            if (head->Coef != 0) {
                cout << (head->Coef < 0 ? "-" : "+") << (head->Coef != 1 && head->Coef != -1 || head->Grade == 0 ? to_string(abs(head->Coef)) : "")
                     << (head->Grade != 0 ? (head->Grade != 1 ? ("X^" + to_string(head->Grade)) : "X") : "");
            }
        }

        nodes += 1;
        head = head->Next;
    }
    cout << endl;
}

void sumPolynoms(Node *&P, Node *Q) {
    Node *aux = P;
    while (aux != NULL && Q != NULL) {
        if (aux->Grade < Q->Grade && Q->Coef != 0) {
            createNode(P, Q->Grade, Q->Coef);
            Q = Q->Next;

            continue;
        }
        else if (aux->Grade == Q->Grade && Q->Coef != 0) {
            aux->Coef += Q->Coef;

            aux = aux->Next;
            Q = Q->Next;

            continue;
        }
        else if (aux->Grade > Q->Grade) {
            aux = aux->Next;

            continue;
        }
    }
}

double evaluatePolinom(Node *head, double point) { // complexitate O(N * log(P)) -> unde N este lungimea listei
    double result = 0.0;
    while (head != NULL) {
        result = result + head->Coef * pow(point, head->Grade); // exponentierea este logaritmica conform doc.
        head = head->Next;
    }
    return result;
}

int main() {
    // polinom monic <=> coef term dominant = 1.
    // sa zicem ca avem doua polinoame de tipul P = x^2 + 3x + 1 si Q = x^3 + 3x^2 + 2
    createNode(P, 0, 1);
    createNode(P, 1, 3);
    createNode(P, 2, 1);

    createNode(Q, 0, 2);
    createNode(Q, 2, 3);
    createNode(Q, 3, 1);
    createNode(Q, 4, 1);
    createNode(Q, 5, -1);
    createNode(Q, 6, -3);

    // ex. 1
    int scalar;
    cin >> scalar;

    multiplyWithScalar(P, scalar);
    showPolinom(P);

    // ex. 2
    double point;
    cin >> point;

    cout << "Rezultatul lui f(" << point << ") = " << evaluatePolinom(P, point) << endl;

    // ex. 3
    sumPolynoms(P, Q); // se bazeaza pe ex 2.
    showPolinom(P);
    return 0;
}
