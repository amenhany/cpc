#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    int a[101][101], prefix[101][101];

    for (int i = 0; i <= n; i++) {
        a[0][i] = 0;
        a[i][0] = 0;
        prefix[0][i] = 0;
        prefix[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            prefix[i][j] += a[i][j] + prefix[i][j-1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] += prefix[i-1][j];
        }
    }

    int max = prefix[1][1];
    for (int r1 = 1; r1 <= n; r1++) {
        for (int c1 = 1; c1 <= n; c1++) {
            for (int r2 = r1; r2 <= n; r2++) {
                for (int c2 = c1; c2 <= n; c2++) {
                    int temp = prefix[r2][c2] - prefix[r2][c1-1] - prefix[r1-1][c2] + prefix[r1-1][c1-1];
                    if (temp > max) max = temp;
                }
            }
        }
    }

    cout << max << endl;
    
}