#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;


int distribute(int n) {
    if (n%3 == 0) return n/3;
    else if (n%2 == 0) return n/2;
    else return n;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int ans = k;
    for (int i = 0; i <= k; i++) {
        if (n%3 && n%2) ans = n;
        else {
            int share = distribute(n-i) + i;
            ans = std::max(ans, share);
        }
    }

    cout << ans << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) solve();
}