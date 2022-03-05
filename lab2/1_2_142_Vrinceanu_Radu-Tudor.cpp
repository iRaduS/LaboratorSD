#include <iostream>
using namespace std;

unsigned int partition(int[], int, int);
void quickSort(int v[], int left, int right) {
    if (left < right) {
        unsigned int p = partition(v, left, right);

        quickSort(v, left, p - 1);
        quickSort(v, p + 1, right);
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