#include <iostream>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int t;
    std::cin >> t;

    while (t--) {
        int percentIncrease, originalOranges;
        std::cin >> originalOranges >> percentIncrease;

        std::cout << originalOranges * 100 / (100 + percentIncrease) << '\n';
    }
}