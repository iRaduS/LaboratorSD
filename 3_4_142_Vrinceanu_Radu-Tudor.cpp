#include <iostream>
#include <vector>
#include <string>
using namespace std;

int indexValue(const vector<string> &v, unsigned int n, const string &x) {
    for (unsigned int i = 0; i <= n; i++) {
        if (v[i] == x) {
            return (int)(i - 1);
        }
    }

    return -1;
}

int main() {
    string x;
    unsigned int n;
    cin >> n >> x;

    vector<string> v(n + 1);
    for (unsigned int i = 0; i <= n; i++) {
        getline(cin, v[i]);
    }
    cout << indexValue(v, n, x);
    return 0;
}