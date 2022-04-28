#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
struct Tree {
    Tree *left, *right;
    T data;
};
Tree<> *root = nullptr;

// inspirat din inserarea din suportul de laborator (doar ca recursiv implementata)
template <typename T = int>
void insertTree(Tree<T> *&localRoot, T value) {
    if (localRoot == nullptr) {
        Tree<T> *current = new Tree<T>;

        current->data = value;
        current->left = current->right = nullptr;
        localRoot = current;

        return;
    }

    if (value > localRoot->data) {
        insertTree(localRoot->right, value);
    } else {
        insertTree(localRoot->left, value);
    }
}

template <typename T = int>
void getRanges(Tree<T> *localRoot, T x, T y) {
    if (localRoot) {
        if (y >= localRoot->data && x <= localRoot->data) {
            cout << localRoot->data << ' ';
        }

        if (y > localRoot->data) getRanges(localRoot->right, x, y);
        if (x < localRoot->data) getRanges(localRoot->left, x, y);
    }
}

int main() {
    insertTree(root, 7);
    insertTree(root, 11);
    insertTree(root, 20);
    insertTree(root, 8);
    insertTree(root, 2);
    insertTree(root, 9);
    insertTree(root, 5);
    insertTree(root, 30);
    insertTree(root, 1);
    insertTree(root, 31);
    insertTree(root, 19);

    int k1 = 5, k2 = 31;
    getRanges(root, k1, k2);
    return 0;
}