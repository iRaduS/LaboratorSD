#include <iostream>
using namespace std;

bool linearSearch(const int v[], unsigned int n, int x) {
    for (int i = 0; i < n; i++) {
        if (v[i] == x) return true;
    }

    return false;
}

int main() {
    unsigned int n, x;
    cin >> n >> x;

    int *p = new int[n];
    for (unsigned int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << "Elementul " << x << (linearSearch(p, n, x) ? " " : " nu ") << "a fost gasit";

    delete[] p;
    return 0;
}