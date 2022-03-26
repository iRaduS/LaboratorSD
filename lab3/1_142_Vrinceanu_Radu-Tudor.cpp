#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node *next;
} *head;

void orderedInsertion(Node *&node, int val) {
    Node *n_node = new Node;

    n_node->value = val;
    n_node->next = NULL;

    if (node == NULL || node->value >= n_node->value) {
        n_node->next = node;
        node = n_node;
    } else {
        Node *temp = node;
        while (temp->next != NULL && temp->next->value < n_node->value)
            temp = temp->next;

        n_node->next = temp->next;
        temp->next = n_node;
    }
}

void deconstructList(Node *&node) {
    Node *temp = node, *aux = NULL;

    while (temp != NULL) {
        aux = temp->next;
        delete temp;
        temp = aux;
    }

    node = NULL;
}

void removeNode(Node *&head, int value) {
    Node *temp = head;

    // 3 cazuri: cand nodul incepe lista (este head-ul) P nextP
    // cand este un nod intre alte 2 noduri -> oldP P nextP procesarea se va face la nivel de oldP sterg P si
    // leg oldP->next = nextP;
    // cand nodul cautat este ultimul oldP P, stergem P si setam oldP->next = NULL; (setat automat, ptr ca
    // implicit P->next este NULL).

    if (temp->value == value) {
        head = temp->next;
        delete temp;
    } else {
        while (temp != NULL && temp->next != NULL && temp->next->value != value) {
            temp = temp->next;
        }

        if (temp->next == NULL) { // nu exista elementul cerut (ajunge la capatul listei)
            return;
        } else {
            Node *aux = temp->next;
            temp->next = aux->next;

            delete aux;
        }
    }
}

void traverseList(Node *head) {
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0, value; i < n; i++) {
        cin >> value;
        orderedInsertion(head, value);
    }

    cin >> n;
    removeNode(head, n); // sterge nodul cu valoarea x.

    traverseList(head);
    deconstructList(head); // -> sterge toata lista (ramane comentat)
    return 0;
}