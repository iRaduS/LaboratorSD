#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node *next;
} *firstNumber, *secondNumber;

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

void sumLists(Node *&headFirst, Node *&headSecond) {
    Node *remaining = NULL;
    int sumCarry = 0, currentDigit; // luam cifra de carry in cazul in care adunarea nu da o cifra ci un numar

    while (headFirst != NULL && headSecond != NULL) {
        currentDigit = headFirst->value + headSecond->value + sumCarry;

        headFirst->value = currentDigit % 10; // daca este numar rezultatul din currentDigit ma intereseaza doar cif. unitatilor
        sumCarry = currentDigit / 10; // urmand ca si carry-ul sa aiba grija sa ia cifra zecilor din rezultat
        remaining = headFirst;

        headFirst = headFirst->next;
        headSecond = headSecond->next;
    }

    if (headSecond != NULL) { // daca a mai ramas ceva pe a doua lista trebuie reluata procesarea pentru lista 1
        remaining->next = headSecond;
    }
    headFirst = remaining->next;

    while (headFirst != NULL) { // se reproceseaza lista in cazul in care a mai ramas ceva
        currentDigit = headFirst->value + sumCarry;

        headFirst->value = currentDigit % 10;
        sumCarry = currentDigit / 10;
        remaining = headFirst;

        headFirst = headFirst->next;
    }

    if (sumCarry != 0) {
        remaining->next = new Node;
        remaining->next->value = sumCarry;
        remaining->next->next = NULL;
    }
}

void showList(Node *head) {
    if (head != NULL) {
        showList(head->next);

        cout << head->value;
    }
}

int main() {
    // presupunem ca vrem sa facem o adunare pentru 2325 si 123
    // vom propune un algoritm de complexitate O(max(firstNumber.length, secondNumber.length))

    // daca listele nu ar fi fost date in conditia aceasta atunci algoritmul ar fi avut o complexitate mai mare
    // O(firstNumber.length + secondNumber.length) -> date de functiile de inversare ale listelor

    // firstNumber = 5 -> 2 -> 3 -> 2 -> NULL
    // secondNumber = 3 -> 2 -> 1 -> NULL

    createNode(firstNumber, 2);
    createNode(firstNumber, 4);
    createNode(firstNumber, 3);
    createNode(firstNumber, 2);
    createNode(firstNumber, 5);

    createNode(secondNumber, 1);
    createNode(secondNumber, 2);
    createNode(secondNumber, 3);

    Node *aux = firstNumber;
    sumLists(firstNumber, secondNumber); // rezultatul e salvat in prima lista

    showList(aux); // afiseaza numarul cerut... O(max(firstNumber.length, secondNumber.length) + 1? (cifra de carry))
    // = O(max(firstNumber.length, secondNumber.length))
    return 0;
}