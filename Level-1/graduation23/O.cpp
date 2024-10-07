#include <iostream>
#include <cmath>


void solve() {
    int n;
    std::cin >> n;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        sum += input;
    }

    if (std::sqrt(sum) == (long long)std::sqrt(sum)) {
        std::cout << "YES" << '\n';
    } else std::cout << "NO" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}