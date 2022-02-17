#include <iostream>
using namespace std;

bool binarySearch(const int v[], unsigned int n, int x) {
    unsigned int st = 0, dr = n - 1, mij;

    while (st <= dr) {
        mij = st + (dr - st) / 2;

        if (v[mij] == x) {
            return true;
        }

        if (v[mij] > x) {
            dr = mij - 1;
        } else {
            st = mij + 1;
        }
    }

    return false;
}

int main() {
    int x;
    unsigned int n;
    cin >> n >> x;

    int *p = new int[n]; // presupunem p[0...n-1] citit in ordine
    for (unsigned int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << "Elementul " << x << (binarySearch(p, n, x) ? " " : " nu ") << "a fost gasit";

    delete[] p;
    return 0;
}