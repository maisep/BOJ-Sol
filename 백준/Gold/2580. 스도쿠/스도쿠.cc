#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9));
vector<pair<int, int>> zeropos;
int zerocnt = 0;
bool is_find = false;

bool check(int& low, int& col) {
    for (int i = 0; i < 9; i++) {
        if (i != col && sudoku[low][i] == sudoku[low][col]) {
            return false;
        }
        if (i != low && sudoku[i][col] == sudoku[low][col]) {
            return false;
        }
    }

    int tmp_1 = 3 * (int)(low / 3);
    int tmp_2 = 3 * (int)(col / 3);

    for (int i = tmp_1; i < tmp_1 + 3; i++) {
        for (int j = tmp_2; j < tmp_2 + 3; j++) {
            if (i != low && j != col) {
                if (sudoku[i][j] == sudoku[low][col]) {
                    return false;
                }
            }
        }
    }

    return true;
}

void solution(int idx) {
    if (idx == zerocnt) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << "\n";
        }

        is_find = true;
        return;
    }

    if (is_find)
        return;

    int x = zeropos[idx].first;
    int y = zeropos[idx].second;

    for (int i = 1; i < 10 && !is_find; i++) {
        sudoku[x][y] = i;
        if (check(x, y)) {
            solution(idx + 1);
        }
        sudoku[x][y] = 0;
    }
}

int main() {
    

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if (!sudoku[i][j]) {
                zeropos.push_back({ i, j });
                zerocnt++;
            }
        }
    }

    solution(0);

    return 0;
}