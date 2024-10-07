#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::cin;
using std::cout;
using std::string;
using std::vector;
typedef long long ll;


void solve() {
    int months, salary;
    cin >> months >> salary;

    vector<int> cost(months);
    for (int i = 0; i < months; i++) cin >> cost[i];

    int bank = 0, happiness = 0;
    std::priority_queue<int> expensive;
    for (int i = 0; i < months; i++) {
        if (cost[i] <= bank) {
            bank -= cost[i];
            happiness++;
            expensive.push(cost[i]);
        } else if (!expensive.empty() && expensive.top() > cost[i]) {
            bank += expensive.top() - cost[i];
            expensive.pop();
            expensive.push(cost[i]);
        }
        bank += salary;
    }

    cout << happiness << '\n';  
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) solve();
}