#include <iostream>
#include <algorithm>
using namespace std;

struct personDetail {
    unsigned int ht, wt;
};

void personSort(personDetail v[], int n) {
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = i + 1; j < n; j++) {
            if (v[i].ht <= v[j].ht && v[i].wt <= v[j].wt) {
                swap(v[i], v[j]);
            }
        }
    }
}

int main() {
    unsigned int n;
    cin >> n;

    auto *p = new personDetail[n];
    for (unsigned int i = 0; i < n; i++) {
        cin >> p[i].ht >> p[i].wt;
    }

    personSort(p, n);

    unsigned int maxCounter = 1, c = 1;
    for (unsigned int i = 1; i < n; i++) {
        if (p[i].ht <= p[i - 1].ht && p[i].wt <= p[i - 1].wt) {
            c++;
        } else {
            maxCounter = max(c, maxCounter);
            c = 1;
        }
    }

    maxCounter = max(c, maxCounter);
    cout << maxCounter;

    delete[] p;
    return 0;
}