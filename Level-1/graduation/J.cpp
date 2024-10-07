#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::vector;
typedef long long ll;



int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, s;
    cin >> n >> s;

    ll a[n], actualSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        actualSum += a[i];
    }

    if (actualSum == s) cout << n << '\n';
    else cout << n-1 << '\n';
}