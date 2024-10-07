#include <iostream>
#include <vector>
#include <stack>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

while (true) {

    long long num, input, counter = 1;
    std::cin >> num;
    if (num == 0) {
        // std::cout << "yes";
        break;
    }

    std::vector<int> normalRoad(num);
    std::stack<int> narrowRoad;

    for (int i = 0; i < num; i++) {
        std::cin >> normalRoad[i];
    }

    bool flag = true;
    for (int i = 0; i < num; i++) {
        while (!narrowRoad.empty() && narrowRoad.top() == counter) {
            narrowRoad.pop();
            counter++;
        }
        if (normalRoad[i] == counter) counter++;
        else if (!narrowRoad.empty() && narrowRoad.top() < normalRoad[i]) {
            flag = false;
            break;
        }
        else narrowRoad.push(normalRoad[i]);
    }

    if (flag) std::cout << "yes" << '\n';
    else std::cout << "no" << '\n';

    }
}