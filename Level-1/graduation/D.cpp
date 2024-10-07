#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::vector;
typedef long long ll;



int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    string command;
    vector<int> vertices(n);
    vector<std::pair<int, int>> pairs;
    std::stack<int> connected;
    for (int i = 0; i < 2*n; i++) {
        cin >> command >> vertices[i];

        if (command == "in") connected.push(vertices[i]);
        else if (!connected.empty()) {
            int temp = connected.top();
            connected.pop();
            if (!connected.empty()) pairs.push_back({temp, connected.top()});
        }
    }

    // while (!connected.empty()) {
    //     int temp = connected.top();
    //     connected.pop();
    //     if (!connected.empty()) pairs.push_back({temp, connected.top()});
    // }

    for (int i = 0; i < pairs.size(); i++) {
        cout << pairs[i].first << ' ' << pairs[i].second << '\n';
    }
}