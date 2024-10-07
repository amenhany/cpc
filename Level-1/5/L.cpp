#include <iostream>
#include <deque>
#include <string>
#include <algorithm>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n;
    std::cin >> n;
    std::deque<int> dq(n);

    for (int i = 0; i < n; i++) {
        std::cin >> dq[i];
    }

    std::string moves = "";
    int prev;
    if (dq.front() <= dq.back()) {
        prev = dq.front();
        dq.pop_front();
        moves += 'L';
    }
    else {
        prev = dq.back();
        dq.pop_back();
        moves += 'R';
    }

    while (!dq.empty()) {
        if (dq.front() > prev && dq.back() > prev) {
            if (dq.front() <= dq.back()) {
                prev = dq.front();
                dq.pop_front();
                moves += 'L';
            }
            else if (dq.back() < dq.front()) {
                prev = dq.back();
                dq.pop_back();
                moves += 'R';
            }
        }
        else if (dq.front() > prev) {
            prev = dq.front();
            dq.pop_front();
            moves += 'L';
        }
        else if (dq.back() > prev) {
            prev = dq.back();
            dq.pop_back();
            moves += 'R';
        }
        else break;
    }

    std::cout << moves.length() << '\n' << moves << '\n';
}