#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::vector;
typedef long long ll;


void solve();

int binary_search_range(vector<int> &, int, int, int);

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
        solve();
}

void solve() {
    int n, sum;
    cin >> n >> sum;

    vector<int> prefix(n);
    cin >> prefix[0];
    for (int i = 1; i < n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }

    int ans = 2e5;
    if (prefix[n-1] < sum) ans = -1;
    else for (int i = 0; i <= n; i++) {
        int res = n - binary_search_range(prefix, n, sum, i-1) + i;
        ans = std::min(ans, res);
    }

    cout << ans << '\n';
}

int binary_search_range(vector<int> &prefix, int n, int target, int initial) {
    int st = 0, ed = n-1, md, ans = 2e5;

    while (st <= ed) {
        int md = (st + ed)/2;
        if (prefix[md] - initial == target) {
            ans = std::min(ans, md);
            ed = md - 1;
        } else if (prefix[md] - initial < target) st = md + 1;
        else ed = md - 1;
    }

    return ans;
}