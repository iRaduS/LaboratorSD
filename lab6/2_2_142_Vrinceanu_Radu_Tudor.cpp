#include <iostream>
using namespace std;

int hash(int x) {
    return x % 11;
}

int main() {
    int *p = new int[11];
    for (unsigned int i = 0; i < 11; i++) {
        p[i] = -1;
    }
    int v[] = {24, 60, 35, 70, 13, 49, 59, 68};

    for (int i : v) {
        int ind = ::hash(i);
        if (p[ind] == -1) {
            p[ind] = i;
        } else {
            while (p[ind] != -1) ind++;
            p[ind] = i;
        }
    }

    for (unsigned int i = 0; i < 11; i++) {
        cout << i << ": " << p[i] << endl;
    }
    delete[] p;
    return 0;
}