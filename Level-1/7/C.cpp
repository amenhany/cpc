#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::string;
using std::vector;
typedef long long ll;


int binary_search_biggest(vector<ll> &, int, int);

void solve() {
    int candyNum, q;
    cin >> candyNum >> q;

    vector<ll> candyPrefix(candyNum);
    for (int i = 0; i < candyNum; i++) cin >> candyPrefix[i];

    std::sort(candyPrefix.begin(), candyPrefix.end(), std::greater<int>());
    for (int i = 1; i < candyNum; i++) candyPrefix[i] += candyPrefix[i-1];

    while (q--) {
        ll requiredSugar, minimumCandies = 0;
        cin >> requiredSugar;
        if (requiredSugar > candyPrefix[candyNum - 1]) minimumCandies = -1;
        else minimumCandies = binary_search_biggest(candyPrefix, candyNum, requiredSugar) + 1;

        cout << minimumCandies << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) solve();
}

int binary_search_biggest(vector<ll> &a, int n, int target) {
    int st = 0, ed = n-1, md, ans;

    while (st <= ed) {
        md = (st + ed)/2;
        if (a[md] == target) return md;

        else if (a[md] > target) {
            ans = md;
            ed = md - 1;
        }

        else st = md + 1;
    }

    return ans;
}