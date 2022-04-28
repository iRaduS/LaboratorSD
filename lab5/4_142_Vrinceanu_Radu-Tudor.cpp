#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
struct Tree {
    Tree *left, *right;
    T data;
};
Tree<char> *root = nullptr;

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
void inOrderInverse(Tree<T> *node) {
    if (node != nullptr) {
        inOrderInverse(node->right);
        cout << node->data;
        inOrderInverse(node->left);
    }
}


int main() {
    string str; cin >> str;
    for (char i : str) {
        insertTree(root, i);
    }

    inOrderInverse(root);
    return 0;
}