#include <iostream>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n, b;
    std::cin >> n >> b;

    int a[n];
    for (int i = 0; i < n; i++) std::cin >> a[i];

    int min = a[0], max = b;
    for (int i = 1; i < n; i++) {
        if (a[i] < min) min = a[i];
        else {
            int calculation = b/min*a[i] + b%min;
            if (calculation > max) max = calculation;
        }
    }

    std::cout << max << '\n';
}