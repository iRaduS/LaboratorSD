#include <iostream>
using namespace std;

void buildMaxHeap(int[], unsigned int);
void heapify(int[], unsigned int, unsigned int);

void heapSort(int v[], unsigned int n) {
    buildMaxHeap(v, n);

    for (int i = (int)n - 1; i > 0; i--) {
        swap(v[0], v[i]);
        heapify(v, 0, i);
    }
}

void buildMaxHeap(int v[], unsigned int n) {
    for (int i = (int)n / 2 - 1; i >= 0; i--) {
        heapify(v, (unsigned int)i, n);
    }
}

// presupunem ca ar fi sortat si reformam max-heap-ul
void heapify(int v[], unsigned int i, unsigned int n) {
    int left = 2 * i + 1, right = 2 * i + 2,
        maximum = left < n && v[left] > v[i] ? left : i;

    if (right < n && v[right] > v[maximum]) {
        maximum = right;
    }

    if (maximum != i) {
        swap(v[i], v[maximum]);
        heapify(v, maximum, n);
    }
}

int main() {
    unsigned int n;
    cin >> n;

    int *p = new int[n];
    for (unsigned int i = 0; i < n; i++) {
        cin >> p[i];
    }

    heapSort(p, n);

    for (unsigned int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
    delete[] p;
    return 0;
}