#include <iostream>
#include <map>
using namespace std;

string intToRoman(int num) {
    string s;
    map<int, string> m;

    m[1000] = "M";
    m[900] = "CM";
    m[500] = "D";
    m[400] = "CD";
    m[100] = "C";
    m[90] = "XC";
    m[50] = "L";
    m[40] = "XL";
    m[10] = "X";
    m[9] = "IX";
    m[5] = "V";
    m[4] = "IV";
    m[1] = "I";

    map<int, string>::iterator it, jt;

    while (num != 0) {
        for (it = m.begin(); it != m.end(); it++) {
            if (num - it->first >= 0) {
                jt = it;
            }
        }

        while (num - jt->first >= 0) {
            num -= jt->first;
            s += m[jt->first];
        }
    }

    return s;
}

int main() {
    cout << intToRoman(3999);
    return 0;
}