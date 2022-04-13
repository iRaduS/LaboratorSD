#include <bits/stdc++.h>
using namespace std;

const int plus_sign = 1, minus_sign = -1;
int todigit(char digit) {
    return digit - '0';
}

int resultExpression(string expression) {
    stack<int> s;
    int result = 0, num = 0, sign = 1;

    s.push(sign);
    for (char i : expression) {
        if (isdigit(i)) {
            num = num * 10 + todigit(i);
        } else if (strchr("+-", i)) {
            result += sign * num;
            sign = s.top() * (!(i ^ '+') ? plus_sign : minus_sign);

            num = 0;
        } else if (strchr("()", i)) {
            switch (i ^ '(') {
                case 0: {
                    s.push(sign);
                    break;
                }
                default: {
                    s.pop();
                    break;
                }
            }
        }
    }

    result += sign * num;
    return result;
}

int main() {
    string expression;

    cout << "Introdu expresia: ";
    getline(cin, expression);

    if (expression.empty()) {
        cout << "EROARE: Expresia este goala!\n";
        return 0;
    }

    cout << resultExpression(expression);
    return 0;
}
