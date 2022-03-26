#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node *next;
} *head;

// sa se stearga un nod fara a avea acces la head-ul listei
void createNode(Node *&head, int value) {
    Node *node = new Node;
    node->value = value;

    if (head == NULL) { // nu exista inceputul listei
        head = node;
    } else { // inseram in fata
        node->next = head;
        head = node;
    }
}

void traverseList(Node *head) {
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
}

void deleteNode(Node *&node) {
    node->value = node->next->value;

    Node *p = node->next;
    node->next = node->next->next;

    delete p;
}

int main() {
    // 2 -> 3 -> 4 -> 5 -> 1 -> NULL
    createNode(head, 1);
    createNode(head, 5);
    createNode(head, 4);
    createNode(head, 3);
    createNode(head, 2);

    traverseList(head);
    cout << endl;

    /*
     * Sa presupunem ca vrem sa stergem nodul care contine valoarea 4 i.e.
     * 2 -> 3 -> 5 -> 1 -> NULL
     *
     * defapt ce vom face este sa mutam valoarea din P->next a unui nod in P si next-ul next-ului lui P in P->next si vom sterge
     * P->next inainte ca mutarea sa aiba loc.
     */
    Node *node = head;
    while (node->value != 4) {
        node = node->next;
    }
    deleteNode(node);

    traverseList(head);
    return 0;
}