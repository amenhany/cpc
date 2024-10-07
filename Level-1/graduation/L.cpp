#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::vector;
typedef long long ll;


void solve() {
    string s;
    cin >> s;
    int n = s.length();

    int changes = 0;
    for (int i = 0; i < n/2; i++) {
        int current = s[i] - '0';
        int opposite = s[n - i - 1] - '0';
        if (current != opposite) changes += abs(current - opposite);
    }

    cout << changes << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) solve();
}