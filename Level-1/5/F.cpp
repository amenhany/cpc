#include <iostream>
#include <queue>


/*
for a "bonus" queue, add the input number if it is higher than the top card, otherwise, skip the input.
if we meet an input of 0 (hero card), we add the power of the top card from the queue to the total army power
and pop it from the bonus queue.
*/
void solve() {
    int n;
    std::cin >> n;
    std::priority_queue<long long> bonusCards;

    long long armyPower = 0;
    for (int i = 0; i < n; i++) {
        long long input;
        std::cin >> input;
        if (input == 0 && bonusCards.size() != 0) {
            armyPower += bonusCards.top();
            bonusCards.pop();
        }
        else bonusCards.push(input);
    }

    std::cout << armyPower << '\n';
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}