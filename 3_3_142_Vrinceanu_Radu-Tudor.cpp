#include <iostream>
using namespace std;

int indexValue(int v[], unsigned int n, int x) {
    for (unsigned int i = 0; i < n; i++) {
        if (v[i] == x) {
            return (int)i;
        }
    }
    return -1;
}

int main() {
    unsigned int n;
    int x;
    cin >> n >> x;

    int *p = new int[n];
    for (unsigned int i = 0; i < n; i++) {
        cin >> p[i];
    }
    cout << indexValue(p, n, x);

    delete[] p;
    return 0;
}