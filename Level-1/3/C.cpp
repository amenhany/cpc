#include <iostream>
#include <vector>


void solve() {
    int n;
    std::cin >> n;

    int a[n];
    std::vector<int> freq(n, 0);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        freq[a[i]]++;
    }

    int max = -1;
    for (int i = 1; i < n; i++) {
        if (freq[i-1] && freq[i] && freq[i-1] + freq[i] > max)
            max = freq[i-1] + freq[i];
    }

    std::cout << max << '\n';
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