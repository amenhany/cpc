#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int a[26][26], prefix[26][26];

    for (int i = 0; i <= 25; i++) {
        a[0][i] = 0;
        a[i][0] = 0;
        prefix[0][i] = 0;
        prefix[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        for (int j = 1; j <= m; j++) {
            a[i][j] = temp[j-1] - '0';
            prefix[i][j] = 0;
            prefix[i][j] += a[i][j] + prefix[i][j-1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefix[i][j] += prefix[i-1][j];
        }
    }

    int max = 0;
    for (int r1 = 1; r1 <= n; r1++) {
        for (int c1 = 1; c1 <= m; c1++) {
            for (int r2 = r1; r2 <= n; r2++) {
                for (int c2 = c1; c2 <= m; c2++) {
                    int sum = prefix[r2][c2] - prefix[r2][c1-1] - prefix[r1-1][c2] + prefix[r1-1][c1-1];
                    int temp = 2 * (r2 + c2 - (r1-1) - (c1-1));
                    if (sum == 0 && temp > max) max = temp;
                }
            }
        }
    }

    cout << max << endl;
    
}