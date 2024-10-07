#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::vector;
typedef long long ll;



void solve() {
    int n;
    cin >> n;

    while (n--) {
        int sum = 0;
        for (int i = 0; i < 8; i++) {
            int num;
            cin >> num;
            sum += num;
        }

        cout << sum << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) solve();
}