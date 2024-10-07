#include <iostream>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int t;
    std::cin >> t;

    std::queue<int> q;
    while (t--) {
        int command, input;
        std::cin >> command;

        if (command == 1) {
            std::cin >> input;
            q.push(input);
        }
        else if (command == 2 && !q.empty()) q.pop();
        else if (command == 3) {
            q.empty() ? std::cout << "Empty!" : std::cout << q.front();
            std::cout << '\n';
        }
    }
}