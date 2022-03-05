// Interclasare?
#define MAX_N 1024
#include <iostream>
using namespace std;

int main() {
    unsigned int n, m;
    cin >> n >> m;

    int a[MAX_N], b[MAX_N];
    for (unsigned int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (unsigned int i = 0; i < m; i++) {
        cin >> b[i];
    }

    unsigned int len = m + n - 1, i = n - 1, j = m - 1;

    while (i >= 0 && j >= 0) {
        if (b[j] > a[i]) {
            a[len--] = b[j--];
        }
        else {
            a[len--] = a[i--];
        }
    }

    // verifica restul elementelor
    while (j >= 0) {
        a[len--] = b[j--];
    }

    for (i = 0; i < m + n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}