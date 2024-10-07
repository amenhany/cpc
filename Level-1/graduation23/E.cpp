#include <iostream>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    int a[m], b[m], freq[101] = {0};
    for (int i = 0; i < m; i++) {
        std::cin >> a[i] >> b[i];
        if (a[i] == b[i]) freq[a[i]]++;
        else 
            for (int j = a[i]; j <= b[i]; j++) freq[j]++;
    }

    int i = 1;
    for (; i <= n; i++) {
        if (freq[i] > 1 || freq[i] == 0) {
            std::cout << i << ' ' << freq[i] << '\n';
            break;
        }
    }

    if (i > n) std::cout << "OK" << '\n';
}