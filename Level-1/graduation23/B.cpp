#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n;
    std::cin >> n;

    int ranking[n];
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            int input;
            std::cin >> input;
            sum += input;
        }

        ranking[i] = sum;
    }

    int tom = ranking[0];
    std::sort(ranking, ranking + n, std::greater<int>());
    for (int i = 0; i < n; i++) {
        if (ranking[i] == tom) {
            std::cout << i+1 << '\n';
            break;
        }
    }
}