#include <iostream>
#include <string>
#include <algorithm>


// if x is binary and y bits = 2^y then, x^2 = 2^2y - 2^y+1 + 1 = 2^y(2^y - 2) + 1

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n;
    bool flag = true;
    std::cin >> n;

    int datatypes[n], max = -1;
    for (int i = 0; i < n; i++) {
        std::cin >> datatypes[i];
        if (datatypes[i] > max) max = datatypes[i];
    }

    std::sort(datatypes, datatypes + n);

    for (int i = 1; i < n; i++) {
        if (datatypes[i-1]*2 > datatypes[i] && datatypes[i-1] != datatypes[i]) flag = false;
    }

    if (flag) std::cout << "NO" << '\n';
    else std::cout << "YES" << '\n';
}