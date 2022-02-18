#include <iostream>
using namespace std;

void selectionSort(int v[], unsigned int n) {
    for (unsigned int i = 0, greater; i < n - 1; i++) {
        greater = i;

        for (unsigned int j = i + 1; j < n; j++) {
            if (v[j] > v[greater]) {
                greater = j;
            }
        }

        swap(v[i], v[greater]);
    }
}

int main() {
    unsigned int n;
    cin >> n;

    int *p = new int[n];
    for (unsigned int i = 0; i < n; i++) {
        cin >> p[i];
    }

    selectionSort(p, n);

    for (unsigned int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
    delete[] p;
    return 0;
}