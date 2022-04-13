#include <bits/stdc++.h>
using namespace std;

template<typename T = int>
struct Node {
    int priority;
    T data;

    Node<T> *next;
};

template<typename T>
class PriorityQueue {
private:
    Node<T>* head;
public:
    PriorityQueue();
    void pushQueue(T, int);
    void popQueue();
    void showQueue();
    ~PriorityQueue();
};

template<typename T>
void PriorityQueue<T>::pushQueue(T element, int priority) {
    Node<T> *current = new Node<T>();
    current->data = element;
    current->next = nullptr;
    current->priority = priority;

    if (head == nullptr) {
        head = current;
    } else {
        if (head->priority <= priority) {
            Node<T> *aux = head;
            while (aux->next != nullptr && aux->next->priority < priority)
                aux = aux->next;

            current->next = aux->next, aux->next = current;
        } else
            current->next = head, head = current;
    }
}

template<typename T>
PriorityQueue<T>::PriorityQueue() {
    head = nullptr;
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
    Node<T> *p;

    while (head != nullptr) {
        p = head;
        head = head->next;
        delete p;
    }

    head = nullptr;
}

template<typename T>
void PriorityQueue<T>::popQueue() {
    Node<T> *p = head;
    head = head->next;
    delete p;
}

template<typename T>
void PriorityQueue<T>::showQueue() {
    for (Node<T> *aux = head; aux != nullptr; aux = aux->next)
        cout << aux->data << "(priority: " << aux->priority << ")\n";
}

int main() {
    PriorityQueue<int> pq;
    pq.pushQueue(4, 3);
    pq.pushQueue(3, 1);
    pq.pushQueue(4, 1);
    pq.pushQueue(5, 2);
    pq.pushQueue(2, 2);
    pq.showQueue();

    cout << "\n\n\n";

    pq.popQueue();
    pq.showQueue();
    return 0;
}

