#include <iostream>
#include <deque>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int q;
    std::cin >> q;
    std::deque<int> dq;
    std::multiset<int> ms;

    while (q--) {
        int command;
        std::cin >> command;

        int input;
        switch(command) {
            case 1:
                std::cin >> input;
                dq.push_back(input);
                break;
            case 2:
                if (ms.empty()) {
                    std::cout << dq.front() << '\n';
                    dq.pop_front();
                } else {
                    std::cout << *ms.begin() << '\n';
                    ms.erase(ms.begin());
                }
                break;
            case 3:
                for (auto &i : dq) {
                    ms.insert(i);
                    dq.pop_front();
                }
                break;
        }
    }
}