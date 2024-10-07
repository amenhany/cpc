#include <iostream>
#include <string>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int a[51][51], b[51][51];
    int prefixA[51][51], prefixB[51][51];
    for (int i = 0; i <= 50; i++) {
        a[0][i] = 0;
        a[i][0] = 0;
        b[0][i] = 0;
        b[i][0] = 0;
    }

    int na, ma;
    std::cin >> na >> ma;
    for (int i = 1; i <= na; i++) {
        std::string temp;
        std::cin >> temp;
        for (int j = 1; j <= ma; j++) {
            a[i][j] = temp[j-1] - '0';
        }
    }

    int nb, mb;
    std::cin >> nb >> mb;
    for (int i = 1; i <= nb; i++) {
        std::string temp;
        std::cin >> temp;
        for (int j = 1; j <= mb; j++) {
            b[i][j] = temp[j-1] - '0';
        }
    }

    int ans = -1, X, Y;
    for (int x = -50; x <= 50; x++) {
        for (int y = -50; y <= 50; y++) {
            
            int current = 0;
            for (int i = 1; i <= na; i++) {
                for (int j = 1; j <= ma; j++) {
                    if (i+x >= 0 && i+x <= nb && j+y >= 0 && j+y <= mb) {
                        current += a[i][j] * b[i+x][j+y];
                    }
                }
            }

            if (current > ans) {
                X = x;
                Y = y;
                ans = current;
            }

        }
    }

    std::cout << X << ' ' << Y << '\n';
}