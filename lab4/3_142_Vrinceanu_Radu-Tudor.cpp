#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int n;
    cin >> n;

    vector<int> pairs(n);
    for (unsigned int i = 0; i < n; i++) {
        cin >> pairs[i];
    }

    unordered_map<int, bool> appearances;
    stack<int> configuration;

    for (int number : pairs) {
        if (!appearances[number]) {
            configuration.push(number);
            appearances[number] = true;
        } else {
            if (configuration.top() == number) {
                configuration.pop();
            } else {
                break;
            }
        }
    }

    cout << "Configuratia" << (!configuration.empty() ? " NU" : "")
         << " este buna" << endl;
    return 0;
}