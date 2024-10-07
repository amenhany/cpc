#include <iostream>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n, m, min = 101, ans = 0;
    std::cin >> n >> m;

    int right[n], wrong[m];
    for (int i = 0; i < n; i++) {
        std::cin >> right[i];
        if (right[i] < min) min = right[i];
        if (right[i] > ans) ans = right[i];
    }

    if (min*2 > ans) ans = min*2;

    min = 101;
    for (int i = 0; i < m; i++) {
        std::cin >> wrong[i];
        if (wrong[i] < min) min = wrong[i];
    }

    if (ans >= min) ans = -1;
    std::cout << ans << '\n';
}