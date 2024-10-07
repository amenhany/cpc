#include <iostream>
#include <queue>
#include <deque>

int main() {
    int n, candyGiven;
    std::cin >> n >> candyGiven;
    
    std::deque<int> candyCount(n);
    std::queue<int> kidQueue;
    for (int i = 0; i < n; i++) {
        std::cin >> candyCount[i];
        kidQueue.push(i);
    }

    while (kidQueue.size() > 1) {
        if(candyCount[kidQueue.front()] > candyGiven) {
            candyCount[kidQueue.front()] -= candyGiven;
            kidQueue.push(kidQueue.front());
        }
        kidQueue.pop();
    }

    std::cout << kidQueue.front() + 1 << "\n";
}