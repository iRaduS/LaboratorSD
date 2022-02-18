#include <iostream>
using namespace std;

void insertionSort(int v[], unsigned int n) {
    int pivot;

    for (unsigned int i = 0; i < n; i++) {
        pivot = i;

        while (pivot > 0 && v[pivot] < v[pivot - 1]) {
            swap(v[pivot], v[pivot - 1]);
            pivot--;
        }
    }
}

int main() {
    unsigned int n;
    cin >> n;

    int *p = new int[n];
    for (unsigned int i = 0; i < n; i++) {
        cin >> p[i];
    }

    insertionSort(p, n);

    for (unsigned int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
    delete[] p;
    return 0;
}