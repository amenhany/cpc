#include <iostream>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int t;
    std::cin >> t;

    std::stack<int> st;
    while (t--) {
        int command, input;
        std::cin >> command;

        switch(command) {
            case 1:
                std::cin >> input;
                st.push(input);
                break;
            case 2:
                if (!st.empty()) st.pop();
                break;
            case 3:
                if (st.empty()) std::cout << "Empty!" << '\n';
                else std::cout << st.top() << '\n';
                break;
        }
    }
}