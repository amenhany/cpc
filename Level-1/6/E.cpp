#include <iostream>
#include <map>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n;
    std::cin >> n;
    int a[n][n];

    for (int i = 0; i < n; i++) {
        std::string line;
        std::cin >> line;
        for (int j = 0; j < n; j++) a[i][j] = line[j];
    }

    bool flag = false;
    std::map<char, char> mp;
    mp.insert({'x', a[0][0]});
    mp.insert({'o', a[0][1]});
    if (mp['x'] == mp['o']) flag = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && a[i][j] == mp['x']) continue;
            else if ((n-1-j) == i && a[i][j] == mp['x']) continue;
            else if (i != j && (n-1-j) != i && a[i][j] == mp['o']) continue;
            else {
                flag = true;
                break;
            }
        }
    }

    if (flag) std::cout << "NO" << '\n';
    else std::cout << "YES" << '\n';
}