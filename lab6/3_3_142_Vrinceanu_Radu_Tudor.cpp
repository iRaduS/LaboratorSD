#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    unordered_set<string> searchable, results;
    for (int i = 0, j = s.size() - 10; i <= j; ++i) {
        string str = s.substr(i, 10);

        if (searchable.find(str) != searchable.end())
            results.insert(str);
        searchable.insert(str);
    }

    return vector<string>{results.begin(), results.end()};
}

int main() {
    string s; cin >> s;

    vector<string> v = findRepeatedDnaSequences(s);
    for (auto &str : v) {
        cout << str << ' ';
    }

    return 0;
}