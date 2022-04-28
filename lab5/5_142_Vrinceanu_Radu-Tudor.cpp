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
T LCA(Tree<T> *root, T x, T y) {
    if (root) {
        if (root->data < x && root->data < y) return LCA(root->right, x, y);
        if (root->data > x && root->data > y) return LCA(root->left, x, y);

        return root->data;
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

    cout << "LCA dintre nodul 9 si 31: " << LCA(root, 9, 31) << endl;
    return 0;
}