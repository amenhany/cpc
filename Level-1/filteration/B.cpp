#include <iostream>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int m, d, totalDays, columns;
    std::cin >> m >> d;

    if (m == 2) totalDays = 28;
    else if (m == 4 || m == 6 || m == 9 || m == 11) totalDays = 30;
    else totalDays = 31;

    if (d == 1 && m == 2) columns = 4;
    else if (d + totalDays <= 36) columns = 5;
    else columns = 6;

    std::cout << columns << '\n';
}