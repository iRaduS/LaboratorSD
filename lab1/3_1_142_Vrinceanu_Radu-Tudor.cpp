#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct anagramStructure {
    string str;
    unordered_map<char, int>dictionary;
};

unordered_map<char, int> anagramLetters(const string& s) {
    unordered_map<char, int>dictionary;

    for (char c : s) {
        dictionary[c]++;
    }

    return dictionary;
}

void anagramSort(anagramStructure v[], unsigned int n) {
    int pivot;

    for (unsigned int i = 0; i < n; i++) {
        pivot = i;

        while (pivot > 0 && v[pivot].dictionary != v[pivot - 1].dictionary) {
            swap(v[pivot], v[pivot - 1]);
            pivot--;
        }
    }
}

int main() {
    unsigned int n;
    cin >> n;

    auto *p = new anagramStructure[n];
    for (unsigned int i = 0; i < n; i++) {
        cin >> p[i].str;

        p[i].dictionary = anagramLetters(p[i].str);
    }

    anagramSort(p, n);

    for (unsigned int i = 0; i < n; i++) {
        cout << p[i].str << ' ';
    }
    delete[] p;
    return 0;
}