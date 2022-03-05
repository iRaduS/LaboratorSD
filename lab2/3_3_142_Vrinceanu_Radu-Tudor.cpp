#include <iostream>
using namespace std;

unsigned int partition(int[], int, int);
void insertionSort(int v[], int left, unsigned int n) {
    int pivot;

    for (unsigned int i = left; i < n; i++) {
        pivot = i;

        while (pivot > 0 && v[pivot] < v[pivot - 1]) {
            swap(v[pivot], v[pivot - 1]);
            pivot--;
        }
    }
}

void quickSort(int v[], int left, int right) {
    while (left < right) {
        if (right - left < 10) {
            insertionSort(v, left, right);
        } else {
            unsigned int p = partition(v, left, right);

            if (p - left < right - p) {
                quickSort(v, left, p - 1);
                left = p + 1;
            }
            else {
                quickSort(v, p + 1, right);
                right = p - 1;
            }
        }
    }
}

unsigned int partition(int v[], int left, int right) {
    int pivot = v[right], li = (left - 1);

    for (int hi = left, bound = right - 1; hi <= bound; hi++) {
        if (v[hi] > pivot) {
            swap(v[++li], v[hi]);
        }
    }

    swap(v[li + 1], v[right]);
    return (li + 1);
}

int main() {
    int n;
    cin >> n;

    int *p = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    quickSort(p, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
    delete[] p;
    return 0;
}