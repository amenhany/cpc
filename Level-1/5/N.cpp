#include <iostream>
#include <queue>

int main() {
    int firstDeckNumber, secondDeckNumber, totalDeckNumber;
    std::cin >> totalDeckNumber;

    std::cin >> firstDeckNumber;
    std::queue<int> firstDeck;
    for (int i = 0; i < firstDeckNumber; i++) {
        int input;
        std::cin >> input;
        firstDeck.push(input);
    }

    std::cin >> secondDeckNumber;
    std::queue<int> secondDeck;
    for (int i = 0; i < secondDeckNumber; i++) {
        int input;
        std::cin >> input;
        secondDeck.push(input);
    }

    int gameScore = 0, fightCount = 0;
    while(gameScore == 0) {
        if (firstDeck.front() > secondDeck.front()) {
            firstDeck.push(secondDeck.front());
            firstDeck.push(firstDeck.front());
        } else if (secondDeck.front() > firstDeck.front()) {
            secondDeck.push(firstDeck.front());
            secondDeck.push(secondDeck.front());
        }
        firstDeck.pop();
        secondDeck.pop();
        fightCount++;

        if (firstDeck.size() == 0) gameScore = 2;
        else if (secondDeck.size() == 0) gameScore = 1;

        if (fightCount > 1e4) gameScore = -1;
    }

    if (gameScore == -1)  std::cout << gameScore << '\n';
    else std::cout << fightCount << ' ' << gameScore << '\n';
}