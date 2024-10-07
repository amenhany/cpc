#include <iostream>
#include <vector>

typedef long long ll;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    ll n;
    std::cin >> n;

    std::vector<ll> wormBags(n);
    std::vector<ll> wormPrefix(n, 0);
    for (ll i = 0; i < n; i++) {
        std::cin >> wormBags[i];
        wormPrefix[i] = wormBags[i];
    }

    for (int i = 1; i < n; i++) wormPrefix[i] += wormPrefix[i-1];

    int q;
    std::cin >> q;
    while (q--) {
        ll juicy;
        std::cin >> juicy;

        ll st = 0, end = n-1, md, ans = -1;
        while (st <= end) {
            md = (st + end)/2;
            if (wormPrefix[md] == juicy) {
                ans = md+1;
                break;
            }
            else if (wormPrefix[md] < juicy) st = md+1;
            else {
                end = md-1;
                ans = md+1;
            }
        }

        std::cout << ans << '\n';
    }
}