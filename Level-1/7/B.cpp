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

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    std::sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        int ans = std::upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        cout << ans << ' ';
    }
}