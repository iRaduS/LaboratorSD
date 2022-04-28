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
void preOrder(Tree<T> *node) {
    if (node != nullptr) {
        cout << node->data << ' ';
        preOrder(node->left);
        preOrder(node->right);
    }
}

template <typename T = int>
void inOrder(Tree<T> *node) {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->data << ' ';
        inOrder(node->right);
    }
}

template <typename T = int>
void postOrder(Tree<T> *node) {
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << ' ';
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

    preOrder(root);
    cout << '\n';
    inOrder(root);
    cout << '\n';
    postOrder(root);
    return 0;
}