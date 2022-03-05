#include <iostream>
#include <vector>
using namespace std;

void mergeResult(int v[], unsigned int left, unsigned int mid, unsigned int right);
/*
 * Algoritmul de merge sort imparte vectorul in cate 2 jumatati
 * pana cand ajunge sa combine (merge) rezultatele obtinute.
 *
 * Complexitate Timp: T(n) = 2 * T(n / 2) + O(n)(fct. de merge) = O(n*log(n))
 */

void mergeSort(int v[], unsigned int left, unsigned int right) {
    if (left < right) {
        unsigned int mid = (left + right) / 2;

        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);

        mergeResult(v, left, mid, right);
    }
}

void mergeResult(int v[], unsigned int left, unsigned int mid, unsigned int right) {
    vector<int> lArr((mid - left + 1));
    vector<int> rArr((right - mid));

    for (unsigned int i = left; i <= mid; i++) {
        lArr[i - left] = v[i];
    }

    for (unsigned int i = mid + 1; i <= right; i++) {
        rArr[i - (mid + 1)] = v[i];
    }

    // interclasare intre cele doua array-uri
    unsigned int li = 0, ri = 0, vi = left;
    while (li < mid - left + 1 && ri < right - mid) {
        if (lArr[li] <= rArr[ri]) {
            v[vi++] = lArr[li++];
        } else {
            v[vi++] = rArr[ri++];
        }
    }

    while (li < mid - left + 1) {
        v[vi++] = lArr[li++];
    }

    while (ri < right - mid) {
        v[vi++] = rArr[ri++];
    }
}

int main() {
    unsigned int n;
    cin >> n;

    int *p = new int[n];
    for (unsigned int i = 0; i < n; i++) {
        cin >> p[i];
    }

    mergeSort(p, 0, n - 1);

    for (unsigned int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
    delete[] p;
    return 0;
}