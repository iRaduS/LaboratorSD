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

template<typename T = int>
void deleteWithBoth(Tree<T> *&rightMost, Tree<T> *&toBeDeleted) {
    if (!rightMost->right) {
        toBeDeleted->data = rightMost->data;

        Tree<T>* auxNode = rightMost;
        rightMost = rightMost->left;
        delete auxNode;

        return;
    }

    deleteWithBoth(rightMost->right, toBeDeleted);
}

template<typename T = int>
void deleteNode(Tree<T> *&root, T value) {
    if (root == nullptr) return;

    if (root->data == value) {
        if (!root->right && !root->left) { // cazul trivial cand valoarea este egala cu nodul curent (si nu avem descendenti)
            delete root;
            root = NULL;

            return;
        }

        if (root->right && !root->left) { // cazul trivial cand are unul dintre descendenti
            Tree<T> *auxNode = root;
            root = root->right;

            delete auxNode;
            return;
        }

        if (!root->right && root->left) { // cazul trivial cand are unul dintre descendenti
            Tree<T> *auxNode = root;
            root = root->left;

            delete auxNode;
            return;
        }

        if (root->right && root->left) { // cazul in care are ambii descendenti
            deleteWithBoth(root->left, root);
            return;
        }
    }

    // cazul in care trebuie sa parcurgem arborele verificand relatia de ordine dintre cheia curenta si value
    if (root->data <= value) deleteNode(root->right, value);
    else deleteNode(root->left, value);
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

    deleteNode(root, 1); // delete first node (or the root)

    postOrder(root);
    return 0;
}