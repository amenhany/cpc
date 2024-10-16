#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::sort;
typedef long long ll;

bool isSafePlace(int n, vector<string>& nQueens, int row, int col) {
    for (int i = 0; i < n; i++)
        if (nQueens[i][col] == 'Q') return false;

    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (nQueens[i][j] == 'Q') return false;

    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
        if (nQueens[i][j] == 'Q') return false;

    return true;
}

void solveNQueens(int n, vector<vector<string>>& solutions, vector<string>& nQueens, int row) {
    if (row == n) {
        solutions.push_back(nQueens);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (nQueens[row][col] == '*') continue;

        if (isSafePlace(n, nQueens, row, col)) {
            nQueens[row][col] = 'Q';
            solveNQueens(n, solutions, nQueens, row+1);
            nQueens[row][col] = '.';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, counter = 1;
    cin >> n;
    
    while (n != 0) {
        vector<string> nQueens(n);
        vector<vector<string>> solutions;
        for (int i = 0; i < n; i++) cin >> nQueens[i];
        solveNQueens(n, solutions, nQueens, 0);

        cout << "\nCase " << counter << ": " << solutions.size();
        counter++;
        cin >> n;
    }
}