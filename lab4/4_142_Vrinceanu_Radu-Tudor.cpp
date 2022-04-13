#include <bits/stdc++.h>
using namespace std;

int dirX[4] = {-1, 0, 1, 0},
    dirY[4] = {0, -1, 0, 1};
unsigned int m, k = 2;
queue<pair<int, int>> coord;

bool OK(pair<int, int> p) {
    if (p.first < 0 || p.first >= m || p.second < 0 || p.second >= m)
        return false;
    return true;
}

void fillRecursiv(int* *M, pair<int, int> p) {
    M[p.first][p.second] = (int)k;

    for (unsigned int i = 0; i < 4; i++) {
        pair<int, int> temp = {p.first + dirX[i], p.second + dirY[i]};
        if (OK(temp) && M[temp.first][temp.second] == 1) {
            coord.push(temp);
        }
    }

    while (!coord.empty()) {
        pair<int, int> current = coord.front();
        coord.pop();

        fillRecursiv(M, current);
    }
}
int main() {
    cin >> m;

    int* *M = new int*[m];
    for (unsigned int i = 0; i < m; i++) {
        M[i] = new int[m];
        for (unsigned int j = 0; j < m; j++)
            cin >> M[i][j];
    }

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < m; j++) {
            if (M[i][j] == 1) {
                coord.push({i, j});
                fillRecursiv(M, {i, j});
                k++;
            }
        }
    }

    for (unsigned int i = 0; i < m; i++) {
        for (unsigned int j = 0; j < m; j++) {
            cout << M[i][j] << ' ';
        }
        cout << "\n";
        delete[] M[i];
    }
    delete[] M;
    return 0;
}

