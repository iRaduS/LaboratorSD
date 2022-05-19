#define HASH_KEY_SIZE 11
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node *next;
};

void deleteNodes(Node*& ptr) {
    if (ptr != NULL) {
        deleteNodes(ptr->next);
        delete ptr;
    }
}

class HashTable {
private:
    const int hash_key;
    Node* *nodes;
public:
    ~HashTable() {
        for (unsigned int i = 0; i < hash_key; i++) {
            deleteNodes(nodes[i]);
        }
        delete[] nodes;
    }
    HashTable(int hash_mod_value = HASH_KEY_SIZE) : hash_key(hash_mod_value) {
        nodes = new Node*[hash_mod_value];
        for (unsigned int i = 0; i < hash_mod_value; i++)
            nodes[i] = NULL;
    }
    static int hash(const string& s) {
        return (int)s.size() % HASH_KEY_SIZE;
    }
    void insert(const string& s) {
        int indices = hash(s);

        if (nodes[indices] != NULL) {
            Node *ptr = NULL;
            for (ptr = nodes[indices]; ptr->next != NULL; ptr = ptr->next);

            Node* insertable = new Node; insertable->data = s; ptr->next = insertable;
            insertable->next = NULL;
        } else {
            Node* insertable = new Node; insertable->data = s;
            insertable->next = NULL;
            nodes[indices] = insertable;
        }
    }
    bool search(const string& s) {
        int indices = hash(s);

        Node *ptr;
        for (ptr = nodes[indices]; ptr != NULL && ptr->data != s; ptr = ptr->next);

        return ptr != NULL;
    }
    void show() {
        for (int i = 0; i < hash_key; i++) {
            cout << i << ": | ";
            for (Node *ptr = nodes[i]; ptr != NULL; ptr = ptr->next) {
                cout << ptr->data << " | ";
            }
            cout << endl;
        }
    }
    void remove(const string& s) {
        int i = hash(s);
        Node *ptr = nodes[i];
        if (ptr->data == s) {
            nodes[i] = ptr->next;

            delete ptr;
        } else {
            for ( ; ptr->next->data != s; ptr = ptr->next);
            Node *tmp = ptr->next;

            ptr->next = ptr->next->next;
            delete tmp;
        }
    }
};

int main() {
    HashTable h(11);
    h.insert("Radu Vrinceanu");
    h.insert("Miriam Tudorache");
    h.insert("Stanciu Sergiu");
    h.insert("Mitrica Alexandru");
    h.insert("Sebastian Dobrica");
    h.insert("Marius Fotache");
    h.show();

    if (h.search("Stanciu Sergiu")) {
        cout << "Am gasit!" << endl;
    } else {
        cout << "Nu am gasit!" << endl;
    }
    h.remove("Radu Vrinceanu");
    if (h.search("Radu Vrinceanu")) {
        cout << "Am gasit!" << endl;
    } else {
        cout << "Nu am gasit!" << endl;
    }
    h.remove("Marius Fotache");
    h.show();
    return 0;
}
