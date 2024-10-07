#include <iostream>
#include <list>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n;
    std::string s;
    std::cin >> n >> s;
    std::list<int> v(1, 0);

    auto it = v.begin();
    for (int i = 1; i <= n; i++) {
        if (s[i-1] == 'R') it++;
        it = v.insert(it, i);
    }

    for (auto &i : v) std::cout << i << ' ';
}