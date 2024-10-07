#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<std::string> chat(n);
    std::unordered_set<std::string> order;

    for (int i = 0; i < n; i++) std::cin >> chat[i];

    std::cout << "\n\n";
    for (int i = n-1; i >= 0; i--) {
        if (!order.count(chat[i])) std::cout << chat[i] << '\n';
        order.insert(chat[i]);
    }
}