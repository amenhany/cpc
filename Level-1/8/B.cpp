#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
using std::string;
using std::vector;
typedef long long ll;


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    int k;
    cin >> n >> k;

    vector<ll> div;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n%i == 0) {
            div.push_back(i);
            if (i != (n/i)) div.push_back(n/i);
        }
    }
    sort(div.begin(), div.end());

    if (div.size() < k) cout << -1;
    else cout << div[k-1];
}