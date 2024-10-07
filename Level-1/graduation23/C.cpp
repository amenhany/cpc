#include <iostream>
#include <vector>
#include <algorithm>


void solve() {
    int n, m;
    std::cin >> n >> m;

    int bottom[n], left[m], freq[102] = {0};
    for (int i = 0; i < n; i++) {
        std::cin >> bottom[i];
        freq[bottom[i]]++;
    }
    for (int i = 0; i < m; i++) {
        std::cin >> left[i];
        freq[left[i]]++;
    }

    int cancel = 0;
    for (int i = 1; i <= 101; i++) if (freq[i] > 1) cancel++;
    std::cout << cancel << '\n';
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