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

    int a[n], sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int min;
    if (n > 1) min = sum/2 + sum%2;
    else min = sum;

    cout << min << ' ' << sum << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) solve();
}