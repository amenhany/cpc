#include <iostream>
#include <vector>


void solve() {
    int n;
    std::cin >> n;

    int a[n];
    std::vector<int> freq(101, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        freq[a[i]]++;
    }

    int spy;
    for (int i = 0; i < 101; i++) {
        if (freq[i] == 1) spy = i;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == spy) std::cout << i+1 << '\n';
    }
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